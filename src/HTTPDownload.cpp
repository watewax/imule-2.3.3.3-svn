//
// This file is part of the imule Project.
//
// Copyright (c) 2003-2011 aMule Team ( admin@amule.org / http://www.amule.org )
// Copyright (c) 2002-2011 Timo Kujala ( tiku@users.sourceforge.net )
//
// Any parts of this program derived from the xMule, lMule or eMule project,
// or contributed by third-party developers are copyrighted by their
// respective authors.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA
//


#include <wx/protocol/http.h>


#include "HTTPDownload.h"				// Interface declarations
#include <common/StringFunctions.h>		// Needed for unicode2char
#include "OtherFunctions.h"				// Needed for CastChild
#include "Logger.h"						// Needed for AddLogLine*
#include <common/Format.h>				// Needed for CFormat
#include "InternalEvents.h"				// Needed for CMuleInternalEvent
#include "Preferences.h"
#include <wx/filename.h>				// Needed for wxFileName


#ifndef AMULE_DAEMON
#include "inetdownload.h"	// Needed for inetDownload
#include "muuli_wdr.h"		// Needed for ID_CANCEL: Let it here or will fail on win32
#include "MuleGifCtrl.h"

typedef wxGauge wxGaugeControl;

DECLARE_LOCAL_EVENT_TYPE(wxEVT_HTTP_PROGRESS, wxANY_ID)
DECLARE_LOCAL_EVENT_TYPE(wxEVT_HTTP_SHUTDOWN, wxANY_ID)


class CHTTPDownloadDialog : public wxDialog
{
public:
        CHTTPDownloadDialog(CHTTPDownloadCoroutine* coroutine)
                : wxDialog(wxTheApp->GetTopWindow(), -1, _("Downloading..."),
                           wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxSYSTEM_MENU) {
                downloadDlg(this, true)->Show(this, true);

                m_progressbar = CastChild(ID_HTTPDOWNLOADPROGRESS, wxGaugeControl);
                m_progressbar->SetRange(100);

                m_ani = CastChild(ID_ANIMATE, MuleGifCtrl);
                m_ani->LoadData((const char*)inetDownload, sizeof(inetDownload));
                m_ani->Start();

                m_coroutine = coroutine;
        }

        ~CHTTPDownloadDialog() {
                StopThread();
        }

        void UpdateGauge(int total, int current) {
                CFormat label( wxT("( %s / %s )") );

                label % CastItoXBytes(current);
                if (total > 0) {
                        label % CastItoXBytes(total);
                } else {
                        label % _("Unknown");
                }

                CastChild(IDC_DOWNLOADSIZE, wxStaticText)->SetLabel(label.GetString());

                if (total && (total != m_progressbar->GetRange())) {
                        m_progressbar->SetRange(total);
                }

                if (current && (current <= total)) {
                        m_progressbar->SetValue(current);
                }

                Layout();
        }

private:
        void StopThread() {
                if (m_coroutine) {
                        m_coroutine->Stop();
                        delete m_coroutine;
                        m_coroutine = NULL;
                }
        }

        void OnBtnCancel(wxCommandEvent& WXUNUSED(evt)) {
                AddLogLineN(_("HTTP download cancelled"));
                Show(false);
                StopThread();
        }

        void OnProgress(CMuleInternalEvent& evt) {
                UpdateGauge(evt.GetExtraLong(), evt.GetInt());
        }

        void OnShutdown(CMuleInternalEvent& WXUNUSED(evt)) {
                Show(false);
                Destroy();
        }

        CMuleCoroutine*	m_coroutine;
        MuleGifCtrl* 	m_ani;
        wxGaugeControl* m_progressbar;

        DECLARE_EVENT_TABLE()
};


BEGIN_EVENT_TABLE(CHTTPDownloadDialog, wxDialog)
        EVT_BUTTON(ID_HTTPCANCEL, CHTTPDownloadDialog::OnBtnCancel)
        EVT_MULE_INTERNAL(wxEVT_HTTP_PROGRESS, -1, CHTTPDownloadDialog::OnProgress)
        EVT_MULE_INTERNAL(wxEVT_HTTP_SHUTDOWN, -1, CHTTPDownloadDialog::OnShutdown)
END_EVENT_TABLE()

DEFINE_LOCAL_EVENT_TYPE(wxEVT_HTTP_PROGRESS)
DEFINE_LOCAL_EVENT_TYPE(wxEVT_HTTP_SHUTDOWN)

#endif


CHTTPDownloadCoroutine::CHTTPDownloadCoroutine(const wxString& url, const wxString& filename, const wxString& oldfilename, HTTP_Download_File file_id,
                bool showDialog, bool checkDownloadNewer) :
#ifdef AMULE_DAEMON
          CMuleCoroutine(CMuleCoroutine::DETACHED, 10),
#else
          CMuleCoroutine(showDialog ? CMuleCoroutine::JOINABLE : CMuleCoroutine::DETACHED, 10),
#endif
          m_url(url),
          m_tempfile(filename),
          m_result(-1),
          m_file_id(file_id),
          m_companion(NULL)
{
        if (showDialog) {
#ifndef AMULE_DAEMON
                CHTTPDownloadDialog* dialog = new CHTTPDownloadDialog(this);
                dialog->Show(true);
                m_companion = dialog;
#endif
        }
        // Get the date on which the original file was last modified
        // Only if it's the same URL we used for the last download and if the file exists.
        if (checkDownloadNewer && thePrefs::GetLastHTTPDownloadURL(file_id) == url) {
                wxFileName origFile = wxFileName(oldfilename);
                if (origFile.FileExists()) {
                        AddDebugLogLineN(logHTTP, CFormat(wxT("URL %s matches and file %s exists, only download if newer")) % url % oldfilename);
                        m_lastmodified = origFile.GetModificationTime();
                }
        }
        s_allCoroutines.insert(this);
}


// Format the given date to a RFC-2616 compliant HTTP date
// Example: Thu, 14 Jan 2010 15:40:23 GMT
wxString CHTTPDownloadCoroutine::FormatDateHTTP(const wxDateTime& date)
{
        static const wxChar* s_months[] = { wxT("Jan"), wxT("Feb"), wxT("Mar"), wxT("Apr"), wxT("May"), wxT("Jun"), wxT("Jul"), wxT("Aug"), wxT("Sep"), wxT("Oct"), wxT("Nov"), wxT("Dec") };
        static const wxChar* s_dow[] = { wxT("Sun"), wxT("Mon"), wxT("Tue"), wxT("Wed"), wxT("Thu"), wxT("Fri"), wxT("Sat") };

        return CFormat(wxT("%s, %02d %s %d %02d:%02d:%02d GMT")) % s_dow[date.GetWeekDay(wxDateTime::UTC)] % date.GetDay(wxDateTime::UTC) % s_months[date.GetMonth(wxDateTime::UTC)] % date.GetYear(wxDateTime::UTC) % date.GetHour(wxDateTime::UTC) % date.GetMinute(wxDateTime::UTC) % date.GetSecond(wxDateTime::UTC);
}

bool CHTTPDownloadCoroutine::Continue()
{
#ifndef AMULE_DAEMON
        if (TestDestroy()) {
                CR_EXIT;
        }
        try {
                CR_BEGIN;
                AddDebugLogLineN(logHTTP, wxT("HTTP download coroutine started"));
                
                cont.proxy_data = thePrefs::GetProxyData();
                
                cont.outfile.reset(new wxFFileOutputStream(m_tempfile));
                
                if (!cont.outfile->Ok()) {
                        throw wxString(CFormat(_("Unable to create destination file %s for download!")) % m_tempfile);
                }
                
                if ( m_url.IsEmpty() ) {
                        // Nowhere to download from!
                        throw wxString(_("The URL to download can't be empty"));
                }
                
                cont.proxyAddr = cont.proxy_data->m_proxyHostName;
                cont.proxyAddr << wxT(":") << cont.proxy_data->m_proxyPort;
                
                cont.url_handler . reset(new wxURL(m_url));
                if (cont.url_handler->IsOk()) {
                        cont.url_handler->SetProxy(cont.proxyAddr);
                }
                
                cont.url_read_stream = cont.url_handler->GetInputStream(); // iMule
                if (!cont.url_read_stream) {
                        m_response = 0 ; // iMule (no response with class wxURL)
                        if (m_response == 304) {
                                m_result = HTTP_Skipped;
                                AddDebugLogLineN(logHTTP, wxT("Skipped download because requested file is not newer."));
                                throw wxString(wxEmptyString);
                        } else {
                                m_result = HTTP_Error;
                                throw wxString(CFormat(_("The URL %s returned: %i - Error (%i)!")) % m_url % m_response % m_error);
                        }
                }
                
                cont.download_size = cont.url_read_stream->GetSize();
                if (cont.download_size == -1) {
                        AddDebugLogLineN(logHTTP, wxT("Download size not received, downloading until connection is closed"));
                } else {
                        AddDebugLogLineN(logHTTP, CFormat(wxT("Download size: %i")) % cont.download_size);
                }
                
                cont.current_read = 0;
                cont.total_read = 0;
                do {
                        cont.current_read = 0;
                        while (! cont.url_read_stream->CanRead() && !TestDestroy() && cont.total_read != cont.download_size) {
                                CR_RETURN;
                        }
                        if (! cont.url_read_stream->CanRead()) break;
                        
                        cont.url_read_stream->Read(cont.buffer, cont.MAX_HTTP_READ);
                        cont.current_read = cont.url_read_stream->LastRead();
                        if (cont.current_read) {
                                cont.total_read += cont.current_read;
                                cont.outfile->Write(cont.buffer,cont.current_read);
                                AddDebugLogLineN(logHTTP, CFormat(wxT("wrote %d bytes to %s")) % cont.current_read % cont.outfile->GetFile()->GetName());
                                int current_write = cont.outfile->LastWrite();
                                if (cont.current_read != current_write) {
                                        throw wxString(_("Critical error while writing downloaded file"));
                                } else if (m_companion) {
                                        CMuleInternalEvent * evt = new CMuleInternalEvent(wxEVT_HTTP_PROGRESS);
                                        evt->SetInt(cont.total_read);
                                        evt->SetExtraLong(cont.download_size);
                                        wxQueueEvent(m_companion, evt);
                                }
                        }
                        CR_RETURN;
                } while (cont.current_read && !TestDestroy());
                
                if (cont.current_read == 0) {
                        if (cont.download_size == -1) {
                                // Download was probably succesful.
                                AddLogLineN(CFormat(_("Downloaded %d bytes")) % cont.total_read);
                                m_result = HTTP_Success;
                        } else if (cont.total_read != cont.download_size) {
                                m_result = HTTP_Error;
                                throw wxString(CFormat(_("Expected %d bytes, but downloaded %d bytes")) % cont.download_size % cont.total_read);
                        } else {
                                // Download was succesful.
                                m_result = HTTP_Success;
                        }
                }
                
                if (m_result == HTTP_Success) {
                        thePrefs::SetLastHTTPDownloadURL(m_file_id, m_url);
                }
                
                AddDebugLogLineN(logHTTP, wxT("HTTP download coroutine ended"));
                CR_END;
        } catch (const wxString& error) {
                if (wxFileExists(m_tempfile)) {
                        wxRemoveFile(m_tempfile);
                }
                if (!error.IsEmpty()) {
                        AddLogLineC(error);
                }
        }
        CR_EXIT;
#else
        return 0;
#endif
}


void CHTTPDownloadCoroutine::OnExit()
{
#ifndef AMULE_DAEMON
        if (m_companion) {
                CMuleInternalEvent * termEvent = new CMuleInternalEvent(wxEVT_HTTP_SHUTDOWN);
                wxQueueEvent(m_companion, termEvent);
        }
#endif
        
        // Notice the app that the file finished download
        CMuleInternalEvent * evt = new CMuleInternalEvent(wxEVT_CORE_FINISHED_HTTP_DOWNLOAD);
        evt->SetInt((int)m_file_id);
        evt->SetExtraLong((long)m_result);
        wxQueueEvent(wxTheApp, evt);
        s_allCoroutines.erase(this);
        
        CMuleCoroutine::OnExit();
}


//! This function's purpose is to handle redirections in a proper way.
wxInputStream* CHTTPDownloadCoroutine::GetInputStream(wxHTTP * & url_handler, const wxString& location, bool proxy)
{
        if (TestDestroy()) {
                return NULL;
        }

        if (!location.StartsWith(wxT("http://"))) {
                // This is not a http url
                throw wxString(_("Invalid URL for HTTP download or HTTP redirection (did you forget 'http://' ?)"));
        }

        // Get the host

        // Remove the "http://"
        wxString host = location.Right(location.Len() - 7); // strlen("http://") -> 7

        // I belive this is a bug...
        // Sometimes "Location" header looks like this:
        // "http://www.whatever.com:8080http://www.whatever.com/downloads/something.zip"
        // So let's clean it...

        int bad_url_pos = host.Find(wxT("http://"));
        wxString location_url;
        if (bad_url_pos != -1) {
                // Malformed Location field on header (bug above?)
                location_url = host.Mid(bad_url_pos);
                host = host.Left(bad_url_pos);
                // After the first '/' non-http-related, it's the location part of the URL
                location_url = location_url.Right(location_url.Len() - 7).AfterFirst(wxT('/'));
        } else {
                // Regular Location field
                // After the first '/', it's the location part of the URL
                location_url = host.AfterFirst(wxT('/'));
                // The host is everything till the first "/"
                host = host.BeforeFirst(wxT('/'));
        }

        // Build the cleaned url now
        wxString url = wxT("http://") + host + wxT("/") + location_url;

        int port = 80;
        if (host.Find(wxT(':')) != -1) {
                // This http url has a port
                port = wxAtoi(host.AfterFirst(wxT(':')));
                host = host.BeforeFirst(wxT(':'));
				wxASSERT(port < 1 << 16);
		}

        wxIPV4address addr;
        addr.Hostname(host);
        addr.Service((uint16_t)port);
        if (!url_handler->Connect(addr, true)) {
                throw wxString(_("Unable to connect to HTTP download server"));
        }

        wxInputStream* url_read_stream = url_handler->GetInputStream(url);

        /* store the HTTP response code */
        m_response = url_handler->GetResponse();

        /* store the HTTP error code */
        m_error = url_handler->GetError();

        AddDebugLogLineN(logHTTP, CFormat(wxT("Host: %s:%i\n")) % host % port);
        AddDebugLogLineN(logHTTP, CFormat(wxT("URL: %s\n")) % url);
        AddDebugLogLineN(logHTTP, CFormat(wxT("Response: %i (Error: %i)")) % m_response % m_error);

        if (!m_response) {
                AddDebugLogLineC(logHTTP, wxT("WARNING: Void response on stream creation"));
                // WTF? Why does this happen?
                // This is probably produced by an already existing connection, because
                // the input stream is created nevertheless. However, data is not the same.
                delete url_read_stream;
                throw wxString(_("Invalid response from HTTP download server"));
        }

        if (m_response == 301  // Moved permanently
                        || m_response == 302 // Moved temporarily
                        // What about 300 (multiple choices)? Do we have to handle it?
           ) {

                // We have to remove the current stream.
                delete url_read_stream;

                wxString new_location = url_handler->GetHeader(wxT("Location"));

                url_handler->Destroy();
                if (!new_location.IsEmpty()) {
                        url_handler = new wxHTTP;
                        url_handler->SetProxyMode(proxy);
                        if (m_lastmodified.IsValid()) {
                                // Set a flag in the HTTP header that we only download if the file is newer.
                                // see: http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.25
                                url_handler->SetHeader(wxT("If-Modified-Since"), FormatDateHTTP(m_lastmodified));
                        }
                        url_read_stream = GetInputStream(url_handler, new_location, proxy);
                } else {
                        AddDebugLogLineC(logHTTP, wxT("ERROR: Redirection code received with no URL"));
                        url_handler = NULL;
                        url_read_stream = NULL;
                }
        } else if (m_response == 304) {		// "Not Modified"
                delete url_read_stream;
                url_handler->Destroy();
                url_read_stream = NULL;
                url_handler = NULL;
        }

        return url_read_stream;
}

void CHTTPDownloadCoroutine::StopAll()
{
        CoroutineSet allThreads;
        std::swap(allThreads, s_allCoroutines);
        for (CoroutineSet::iterator it = allThreads.begin(); it != allThreads.end(); it++) {
                (*it)->Stop();
        }
}

CHTTPDownloadCoroutine::CoroutineSet CHTTPDownloadCoroutine::s_allCoroutines;

// File_checked_for_headers