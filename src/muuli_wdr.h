//------------------------------------------------------------------------------
// Header generated by wxDesigner from file: muuli.wdr
// Do not modify this file, all changes will be lost!
//------------------------------------------------------------------------------

#ifndef __WDR_muuli_H__
#define __WDR_muuli_H__

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma interface "muuli_wdr.h"
#endif

// Include wxWidgets' headers

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/image.h>
#include <wx/statline.h>
#include <wx/spinbutt.h>
#include <wx/spinctrl.h>
#include <wx/splitter.h>
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <wx/toolbar.h>
#include <wx/tglbtn.h>
//#include <wx/collpane.h>
#include <wx/hyperlink.h>
//#include <wx/animate.h>
#include <wx/filepicker.h>
#include <wx/datectrl.h>
//#include <wx/fontpicker.h>
//#include <wx/clrpicker.h>
#include <wx/srchctrl.h>
#if wxCHECK_VERSION(2,9,0)
#include <wx/editlbox.h>
#endif

// Declare window functions

extern wxSizer *s_dlgcnt;
extern wxSizer *contentSizer;
extern wxSizer *s_fed2klh;
#define ID_BUTTON_FAST 10000
#define IDC_SHOWSTATUSTEXT 10001
wxSizer *muleDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_SRV_SPLITTER 10002
wxSizer *serverListDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *s_searchsizer;
#define IDC_SEARCHNAME 10003
#define ID_SEARCHTYPE 10004
#define IDC_EXTENDEDSEARCHCHECK 10005
#define IDC_FILTERCHECK 10006
extern wxSizer *s_extendedsizer;
#define IDC_TypeSearch 10007
#define ID_AUTOCATASSIGN 10008
#define IDC_EDITSEARCHEXTENSION 10009
#define IDC_SPINSEARCHMIN 10010
#define IDC_SEARCHMINSIZE 10011
#define IDC_SPINSEARCHMAX 10012
#define IDC_SEARCHMAXSIZE 10013
#define IDC_SPINSEARCHAVAIBILITY 10014
extern wxSizer *s_filtersizer;
#define ID_FILTER_TEXT 10015
#define ID_FILTER 10016
#define ID_FILTER_INVERT 10017
#define ID_FILTER_KNOWN 10018
#define IDC_STARTS 10019
#define IDC_SEARCHMORE 10020
#define IDC_CANCELS 10021
#define IDC_SDOWNLOAD 10022
#define IDC_SEARCH_RESET 10023
#define IDC_CLEAR_RESULTS 10024
#define ID_NOTEBOOK 10025
#define ID_SEARCHPROGRESS 10026
wxSizer *searchDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_BTNCLRCOMPL 10027
#define ID_CATEGORIES 10028
#define ID_DLOADLIST 10029
wxSizer *transferTopPane( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *s_clientlistHeader;
#define ID_CLIENTTOGGLE 10030
#define ID_CLIENTCOUNT 10031
#define ID_CLIENTLIST 10032
wxSizer *transferBottomPane( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_FRIENDLIST 10033
#define IDC_CHATSELECTOR 10034
#define IDC_CMESSAGE 10035
#define IDC_CSEND 10036
#define IDC_CCLOSE 10037
wxSizer *messagePage( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_FNAME 10038
#define IDC_METFILE 10039
#define IDC_FHASH 10040
#define IDC_FSIZE 10041
#define IDC_PFSTATUS 10042
#define IDC_LASTSEENCOMPL 10043
#define IDC_SOURCECOUNT 10044
#define IDC_SOURCECOUNT2 10045
#define IDC_PARTCOUNT 10046
#define IDC_PARTAVAILABLE 10047
#define IDC_DATARATE 10048
#define IDC_DLACTIVETIME 10049
#define IDC_TRANSFERRED 10050
#define IDC_COMPLSIZE 10051
#define IDC_PROCCOMPL 10052
#define IDC_FD_STATS1 10053
#define IDC_FD_STATS2 10054
#define IDC_FD_STATS3 10055
#define IDC_LISTCTRLFILENAMES 10056
#define IDC_TAKEOVER 10057
#define IDC_CMTBT 10058
#define IDC_BUTTONSTRIP 10059
#define IDC_FILENAME 10060
#define IDC_NEXTFILE 10061
#define IDC_PREVFILE 10062
#define IDC_APPLY 10063
#define IDC_APPLY_AND_CLOSE 10064
#define ID_CLOSEWNDFD 5100
wxSizer *fileDetails( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_CMT_TEXT 10065
#define IDC_FC_CLEAR 10066
#define IDC_RATELIST 10067
#define IDCOK 10068
#define IDCCANCEL 10069
wxSizer *commentDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_LST 10070
#define IDC_CMSTATUS 10071
#define IDCREF 10072
wxSizer *commentLstDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_ANIMATE 10073
#define ID_HTTPDOWNLOADPROGRESS 10074
#define IDC_DOWNLOADSIZE 10075
#define ID_HTTPCANCEL 5101
wxSizer *downloadDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_DESTADDRESS 10076
#define ID_USERNAME 10077
#define ID_USERHASH 10078
#define ID_ADDFRIEND 10079
#define ID_CLOSEDLG 10080
wxSizer *addFriendDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_SHARESSPLATTER 10081
wxSizer *sharedfilesDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_DLOADSCOPE 10082
#define IDC_C0 10083
#define IDC_C0_3 10084
#define IDC_C0_2 10085
#define ID_ULOADSCOPE 10086
#define IDC_C1 10087
#define IDC_C1_3 10088
#define IDC_C1_2 10089
#define ID_OTHERS 10090
#define IDC_S3 10091
#define IDC_S0 10092
#define ID_ACTIVEC 10093
#define IDC_S1 10094
wxSizer *statsDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_DNAME 10095
#define ID_DHASH 10096
#define ID_DSOFT 10097
#define ID_DVERSION 10098
#define ID_I2PTCP 10099
#define ID_I2PUDP 10100
#define ID_DSIP 10101
#define ID_DSNAME 10102
#define IDT_OBFUSCATION 10103
#define IDT_KAD 10104
#define ID_DDOWNLOADING 10105
#define ID_DAVDR 10106
#define ID_DAVUR 10107
#define ID_DDOWN 10108
#define ID_DDUP 10109
#define ID_DDOWNTOTAL 10110
#define ID_DUPTOTAL 10111
#define ID_DRATIO 10112
#define IDC_CDIDENT 10113
#define ID_QUEUERANK 10114
#define ID_DSCORE 10115
#define ID_CLOSEWND 10116
wxSizer *clientDetails( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_NICK 10117
#define IDC_LANGUAGE 10118
#define IDC_NEWVERSION 10119
#define IDC_PERUSERCONF 10120
#define IDC_STARTMIN 10121
#define IDC_EXIT 10122
#define IDC_MACHIDEONCLOSE 10123
#define IDC_ENABLETRAYICON 10124
#define IDC_MINTRAY 10125
#define IDC_TOOLTIPDELAY 10126
#define IDC_BROWSERSELF 10127
#define IDC_SELBROWSER 10128
#define IDC_BROWSERTABS 10129
#define IDC_VIDEOPLAYER 10130
#define IDC_BROWSEV 10131
#define IDC_PREVIEW_NOTE 10132
wxSizer *PreferencesGeneralTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_MAXDOWN 10133
#define IDC_MAXUP 10134
#define IDC_SLOTALLOC 10135
#define IDC_UPNP_ENABLED 10136
#define IDC_UPNPTCPPORTTEXT 10137
#define IDC_UPNPTCPPORT 10138
#define IDC_MAXSOURCEPERFILE 10139
#define IDC_MAXCON 10140
#define IDC_NETWORKED2K 10141
#define IDC_NETWORKKAD 10142
#define IDC_AUTOCONNECT 10143
#define IDC_RECONN 10144
wxSizer *PreferencesConnectionTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_REMOVEDEAD 10145
#define IDC_SERVERRETRIES 10146
#define IDC_AUTOSERVER 10147
#define IDC_EDITADR 10148
#define IDC_UPDATESERVERCONNECT 10149
#define IDC_UPDATESERVERCLIENT 10150
#define IDC_SCORE 10151
#define IDC_SMARTIDCHECK 10152
#define IDC_SAFESERVERCONNECT 10153
#define IDC_AUTOCONNECTSTATICONLY 10154
#define IDC_MANUALSERVERHIGHPRIO 10155
wxSizer *PreferencesServerTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_ICH 10156
#define IDC_AICHTRUST 10157
#define IDC_ADDNEWFILESPAUSED 10158
#define IDC_DAP 10159
#define IDC_PREVIEWPRIO 10160
#define IDC_FULLCHUNKTRANS 10161
#define IDC_STARTNEXTFILE 10162
#define IDC_STARTNEXTFILE_SAME 10163
#define IDC_STARTNEXTFILE_ALPHA 10164
#define IDC_ALLOCFULLFILE 10165
#define IDC_CHECKDISKSPACE 10166
#define IDC_MINDISKSPACE 10167
#define IDC_SRCSEEDS 10168
#define IDC_UAP 10169
wxSizer *PreferencesFilesTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_INCFILES 10170
#define IDC_SELINCDIR 10171
#define IDC_TEMPFILES 10172
#define IDC_SELTEMPDIR 10173
#define IDC_SHARESELECTOR 10174
#define IDC_SHAREHIDDENFILES 10175
wxSizer *PreferencesDirectoriesTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_SLIDERINFO 10176
#define IDC_SLIDER 10177
#define IDC_SLIDERINFO3 10178
#define IDC_SLIDER3 10179
#define IDC_SLIDERINFO4 10180
#define IDC_SLIDER4 10181
#define IDC_COLORSELECTOR 10182
#define IDC_COLOR_BUTTON 10183
#define IDC_SLIDERINFO2 10184
#define IDC_SLIDER2 10185
#define IDC_CLIENTVERSIONS 10186
#define IDC_DOWNLOAD_CAP 10187
#define IDC_UPLOAD_CAP 10188
wxSizer *PreferencesStatisticsTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_AMULE_TWEAKS_WARNING 10189
#define IDC_MAXCON5SEC 10190
#define IDC_FILEBUFFERSIZE_STATIC 10191
#define IDC_FILEBUFFERSIZE 10192
#define IDC_QUEUESIZE_STATIC 10193
#define IDC_QUEUESIZE 10194
#define IDC_SERVERKEEPALIVE_LABEL 10195
#define IDC_SERVERKEEPALIVE 10196
#define ID_LINE 10197
#define ID_TEXT 10198
#define IDC_KEEPKADCONTACTS 10199
#define IDC_WRITEMYSELFTONODESDAT 10200
#define IDC_PREVENT_SLEEP 10201
#define IDC_I2PCLIENTNAME 10202
wxSizer *PreferencesaMuleTweaksTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_SKIN 10203
#define IDC_FED2KLH 10204
#define IDC_EXTCATINFO 10205
#define IDC_SHOWVERSIONONTITLE 10206
#define IDC_SHOWRATEONTITLE 10207
#define IDC_RATESBEFORETITLE 10208
#define IDC_RATESAFTERTITLE 10209
#define IDC_SHOWOVERHEAD 10210
#define IDC_VERTTOOLBAR 10211
#define IDC_PERCENT 10212
#define IDC_PROGBAR 10213
#define IDC_3DDEPTH 10214
#define IDC_AUTOSORT 10215
wxSizer *PreferencesGuiTweaksTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_EXT_CONN_ACCEPT 10216
#define IDC_EXT_CONN_IP 10217
#define IDC_EXT_CONN_TCP_PORT 10218
#define IDC_UPNP_EC_ENABLED 10219
#define IDC_EXT_CONN_PASSWD 10220
#define IDC_ENABLE_WEB 10221
#define IDC_WEBTEMPLATE 10222
#define IDC_WEB_PASSWD 10223
#define IDC_ENABLE_WEB_LOW 10224
#define IDC_WEB_PASSWD_LOW 10225
#define IDC_WEB_PORT 10226
#define IDC_UPNP_WEBSERVER_ENABLED 10227
#define IDC_WEBUPNPTCPPORTTEXT 10228
#define IDC_WEBUPNPTCPPORT 10229
#define IDC_WEB_REFRESH_TIMEOUT 10230
#define IDC_WEB_GZIP 10231
wxSizer *PreferencesRemoteControlsTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *prefs_sizer;
#define ID_PREFSLISTCTRL 10232
#define ID_PREFS_OK_TOP 10233
#define ID_PREFS_CANCEL_TOP 10234
wxSizer *preferencesDlgTop( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_TITLE 10235
#define IDC_COMMENT 10236
#define IDC_INCOMING 10237
#define IDC_BROWSE 10238
#define IDC_PRIOCOMBO 10239
#define ID_BOX_CATCOLOR 10240
#define IDC_CATCOLOR 10241
wxSizer *CategoriesEditWindow( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_DOWNLOADSSPLATTER 10242
wxSizer *transferDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_SERVERINFO 10243
#define ID_BTN_RESET_SERVER 10244
wxSizer *ServerInfoLog( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_LOGVIEW 10245
#define ID_BTN_RESET 10246
wxSizer *aMuleLog( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_UPDATELIST 10247
#define IDC_SERVERLISTURL 10248
#define IDC_SERVERNAME 10249
#define IDC_SDEST 10250
#define ID_ADDTOLIST 10251
#define IDC_ED2KDISCONNECT 10252
#define ID_SERVERLIST 10253
wxSizer *serverListDlgUp( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_SRVLOG_NOTEBOOK 10254
wxSizer *serverListDlgDown( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_NODESLISTURL 10255
#define ID_UPDATEKADLIST 10256
#define ID_NODE_DEST 10257
#define ID_NODECONNECT 10258
#define ID_NODEEXPORT 10259
#define ID_MYDESTTOCLIPBOARD 10260
#define ID_SPLITTER 10261
wxSizer *KadDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_ED2KINFO 10262
wxSizer *ED2K_Info( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_SUPPORT_PO 10263
#define IDC_ENABLE_PO_OUTGOING 10264
#define IDC_ENFORCE_PO_INCOMING 10265
#define IDC_SEESHARES 10266
#define IDC_IPFSERVERS 10267
#define IDC_IPFCLIENTS 10268
#define IDC_IPFRELOAD 10269
#define IDC_IPFILTERURL 10270
#define IDC_IPFILTERUPDATE 10271
#define IDC_AUTOIPFILTER 10272
#define ID_IPFILTERLEVEL 10273
#define IDC_PARANOID 10274
#define IDC_SECIDENT 10275
wxSizer *PreferencesSecurityTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_ONLINESIG 10276
#define IDC_OSUPDATE 10277
#define IDC_OSDIR 10278
#define IDC_SELOSDIR 10279
wxSizer *PreferencesOnlineSigTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_MSGFILTER 10280
#define IDC_MSGFILTER_ALL 10281
#define IDC_MSGFILTER_NONFRIENDS 10282
#define IDC_MSGFILTER_NONSECURE 10283
#define IDC_MSGFILTER_WORD 10284
#define IDC_MSGWORD 10285
#define IDC_MSGLOG 10286
#define IDC_FILTERCOMMENTS 10287
#define IDC_COMMENTWORD 10288
wxSizer *PreferencesFilteringTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_PROXY_ENABLE_PROXY 10289
#define ID_PROXY_TYPE 10290
#define ID_PROXY_NAME 10291
#define ID_PROXY_PORT 10292
#define ID_PROXY_ENABLE_PASSWORD 10293
#define ID_PROXY_USER 10294
#define ID_PROXY_PASSWORD 10295
#define ID_PROXY_AUTO_SERVER_CONNECT_WITHOUT_PROXY 10296
wxSizer *PreferencesProxyTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_REMOTE_HOST 10297
#define ID_REMOTE_PORT 10298
#define ID_EC_LOGIN 10299
#define ID_EC_PASSWD 10300
#define ID_EC_SAVE 10301
wxSizer *CoreConnect( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_VERBOSEDEBUG 10302
#define ID_DEBUGCATS 10303
wxSizer *PreferencesDebug( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *IDC_CURJOB;
#define IDC_CONV_PB_LABEL 10304
#define IDC_CONV_PROZENT 10305
#define IDC_CONV_PB_CURRENT 10306
#define IDC_JOBLIST 10307
#define IDC_ADDITEM 10308
#define IDC_RETRY 10309
#define IDC_CONVREMOVE 10310
wxSizer *convertDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_KADINFO 10311
wxSizer *Kad_Info( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *m_networknotebooksizer;
#define ID_NETNOTEBOOK 10312
wxSizer *NetDialog( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *IDC_PREFS_EVENTS_PAGE;
#define IDC_EVENTLIST 10313
wxSizer *PreferencesEventsTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_STATICBITMAP 10314
#define IDC_NNS_HANDLING 10315
#define IDC_ENABLE_AUTO_FQS 10316
#define IDC_ENABLE_AUTO_HQRS 10317
#define IDC_HQR_VALUE 10318
#define IDC_AUTO_DROP_TIMER 10319
wxSizer *PreferencesSourcesDroppingTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_I2PSERVERINTERNAL 10320
#define IDC_I2PSERVERIP 10321
#define IDC_I2PPROXYPORT 10322
#define IDC_I2PSAMTCPPORT 10323
#define IDC_I2PSERVER_ISDYNIP 10324
#define IDC_I2PSERVER_DYNIP 10325
#define IDC_I2PSERVER_I2PTCPPORT 10326
#define IDC_I2PSERVER_I2PUDPPORT 10327
#define IDC_I2PPROP_INBOUND_BANDWIDTH 10328
#define IDC_I2PPROP_OUTBOUND_BANDWIDTH 10329
#define IDC_I2PBANDWIDTHSHAREPERCENTAGE 10330
#define IDC_I2PPROP_INBOUND_BURST_BANDWIDTH 10331
#define IDC_I2PPROP_OUTBOUND_BURST_BANDWIDTH 10332
#define IDC_I2PINBOUNDHOPS 10333
#define IDC_I2POUTBOUNDHOPS 10334
#define ID_I2PNBTCPTUNNELS 10335
#define IDC_I2PNBUDPTUNNELS 10336
#define IDC_I2PNBTCPTUNNELS 10337
wxSizer *PreferencesI2PConnectionTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_KadDlgNodesList 10338
wxSizer *KadDlgNodesList( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *kadDlgNodesGraphFrame;
#define ID_KADSCOPE 10339
wxSizer *KadDlgNodesGraph( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define IDC_CB_TBN_USESOUND 10340
#define IDC_EDIT_TBN_WAVFILE 10341
#define IDC_BTN_BROWSE_WAV 10342
#define IDC_CB_TBN_ONCHAT 10343
#define IDC_CB_TBN_POP_ALWAYS 10344
#define IDC_CB_TBN_ONDOWNLOAD 10345
#define IDC_CB_TBN_ONNEWVERSION 10346
#define IDC_CB_TBN_IMPORTATNT 10347
#define IDC_SENDMAIL 10348
#define IDC_SMTP 10349
#define IDC_EMAIL 10350
wxSizer *PreferencesNotifyTab( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_ROUTERSTATUS 10351
#define ID_BTN_UPDATE_ROUTERSTATUS 10352
wxSizer *RouterStatus( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

extern wxSizer *s_sharedfilespeerHeader;
#define ID_SHAREDCLIENTTOGGLE 10353
#define IDC_SREQUESTED 10354
#define IDC_SACCEPTED 10355
#define IDC_STRANSFERRED 10356
#define ID_GAUGE 10357
#define ID_SHAREDCLIENTLIST 10358
wxSizer *sharedfilesBottomDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

#define ID_SHOW_CLIENTS_MODE 10359
#define ID_BTNRELSHARED 10360
#define ID_SHFILELIST 10361
wxSizer *sharedfilesTopDlg( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

wxSizer *messagePageFriends( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

wxSizer *messagePageMessages( wxWindow *parent, bool call_fit = true, bool set_sizer = true );

// Declare menubar functions

// Declare toolbar functions

#define ID_BUTTONCONNECT 10362
#define ID_BUTTONNETWORKS 10363
#define ID_BUTTONSEARCH 10364
#define ID_BUTTONDOWNLOADS 10365
#define ID_BUTTONSHARED 10366
#define ID_BUTTONMESSAGES 10367
#define ID_BUTTONSTATISTICS 10368
#define ID_BUTTONNEWPREFERENCES 10369
#define ID_BUTTONIMPORT 10370
#define ID_ABOUT 10371
void muleToolbar( wxToolBar *parent );

// Declare bitmap functions

wxBitmap clientImages( size_t index );

wxBitmap dlStatusImages( size_t index );

wxBitmap connImages( size_t index );

wxBitmap moreImages( size_t index );

wxBitmap amuleSpecial( size_t index );

wxBitmap connButImg( size_t index );

wxBitmap amuleDlgImages( size_t index );

#endif

// End of generated file
