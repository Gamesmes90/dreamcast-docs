///////////////////////////////////////////////////////////////////////////////
//
//  File Name 
//      WINDSADM.H
//
//  Description
//
//  Author
//      Irving De la Cruz
//
//  Revision: 1.7
//
// Written for Microsoft Windows Developer Support
// Copyright (c) 1995-1996 Microsoft Corporation. All rights reserved.
//
#ifndef _WINDSADM_H
#define _WINDSADM_H

#define STRICT
#include <WINDOWS.H>
#include <WINDOWSX.H>
#include <COMMDLG.H>
#include <COMMCTRL.H>
#include "WRAP3D.H"

#ifdef _DEBUG
#define ENABLE_DEBUG_OUTPUT     1
#endif // _DEBUG
#define TRACES_NO_MAPI          1

#include "TRACES.H"
#include "RESOURCE.H"

#include <RPC.H>
#include "WDSADM.H"    // Header file generated by the MIDL compiler
#include "WINDSGBL.H"

//  CTL3D wrapper
extern "C" LPVOID g_pctl3d;

#ifdef UNICODE
#error WINDS Administrator: Not ready for UNICODE yet... IrvingD (9/10/95)
#define RemoteAdmTerminateNotif     RemoteAdmTerminateNotifW
#define RemoteAdmValidateNotif      RemoteAdmValidateNotifW
#define RemoteAdmCreateMailbox      RemoteAdmCreateMailboxW
#define RemoteAdmGetMailboxProps    RemoteAdmGetMailboxPropsW
#define RemoteAdmSetMailboxProps    RemoteAdmSetMailboxPropsW
#define RemoteAdmCreateDistList     RemoteAdmCreateDistListW
#define RemoteAdmGetDLProps         RemoteAdmGetDLPropsW
#define RemoteAdmSetDLProps         RemoteAdmSetDLPropsW
#define ADMIN_DL_MEMBERS            ADMIN_DL_MEMBERS_W
#define DLM_LIST                    DLM_LIST_W
#define DLM_INFO                    DLM_INFO_W
#define ADM_MAILBOX_INFO            ADM_MAILBOX_INFO_W
#else
#define RemoteAdmTerminateNotif     RemoteAdmTerminateNotifA
#define RemoteAdmValidateNotif      RemoteAdmValidateNotifA
#define RemoteAdmCreateMailbox      RemoteAdmCreateMailboxA
#define RemoteAdmGetMailboxProps    RemoteAdmGetMailboxPropsA
#define RemoteAdmSetMailboxProps    RemoteAdmSetMailboxPropsA
#define RemoteAdmCreateDistList     RemoteAdmCreateDistListA
#define RemoteAdmGetDLProps         RemoteAdmGetDLPropsA
#define RemoteAdmSetDLProps         RemoteAdmSetDLPropsA
#define ADMIN_DL_MEMBERS            ADMIN_DL_MEMBERS_A
#define DLM_LIST                    DLM_LIST_A
#define DLM_INFO                    DLM_INFO_A
#define ADM_MAILBOX_INFO            ADM_MAILBOX_INFO_A
#endif // UNICODE

enum
{
    IMG_MAILABLE_OBJECTS_CLOSE  = 0,
    IMG_MAILABLE_OBJECTS_OPEN,
    IMG_PUBLIC_FOLDER,
    IMG_USER,
    IMG_FOREIGN_USER,
    IMG_MAIL_GROUP,
    IMG_DIST_LIST,
    IMG_SERVER_PUB_FOLDER,
    IMG_SERVER,
    IMG_SERVER_OBJECTS,
    IMG_SERVER_GATEWAY,
    IMG_GATEWAY,
    IMG_USER_MAILBOX,
    IMG_FOLDER_CLOSE,
    IMG_FOLDER_OPEN,
};

enum
{
    ICON_AUTO_REPLY     = 0,
    ICON_CONSTRUCT,
    ICON_DL_MEMBERS,
    ICON_LABELS,
    ICON_LARGE_ENVEL,
    ICON_MAILBOX,
    ICON_PHONE_HAND,
    ICON_KEY,
    ICON_PEOPLE,
    ICON_DL_OWNER,
    ICON_CONNECT,
    ICON_TIMEUP,
    ICON_WORLD,
    ICON_CLIP
};

#define WM_WINDS_UPDATEHEADERWIDTH          (WM_USER + 100)
#define WM_WINDS_REMOTE_CALL_IN_PROGRESS    (WM_USER + 101)
#define WM_WINDS_REMOTE_CALL_COMPLETED      (WM_USER + 102)
#define WM_WINDS_RESET_NOTIF_LINK           (WM_USER + 103)
#define WM_WINDS_IMPORT_START               (WM_USER + 104)
#define WM_WINDS_IMPORT_FINISHED            (WM_USER + 105)
#define WM_WINDS_EXPORT_START               (WM_USER + 106)
#define WM_WINDS_EXPORT_FINISHED            (WM_USER + 107)

typedef enum _ITEM_TYPE
{
    ITEM_UNDEFINED_TYPE,
    ITEM_SERVER_USER_MAILBOXES,
    ITEM_SERVER_DIST_LISTS,
    ITEM_SERVER_FOREIGN_MAILBOXES,
    ITEM_SERVER_PUBLIC_FOLDERS,
    ITEM_SERVER_GATEWAYS,
    ITEM_REMOTE_SERVER,
    ITEM_OBJECT_DIRECTORY
} ITEM_TYPE;

typedef struct _OBJECT_INFO_A
{
    DWORD               dwData;
    WINDS_AB_OBJTYPE    Type;
    MAILBOX_INFO_A      MB;
    DIST_LIST_INFO_A    DL;
    DLM_LIST_A *        pMembers;
} OBJECT_INFO_A, *POBJECT_INFO_A;

#ifdef UNICODE
#define OBJECT_INFO     OBJECT_INFO_W
#define POBJECT_INFO    POBJECT_INFO_W
#else
#define OBJECT_INFO     OBJECT_INFO_A
#define POBJECT_INFO    POBJECT_INFO_A
#endif // UNICODE

extern "C"
{
    extern ITEM_TYPE g_LVItemsType;
    extern HINSTANCE ghInstance;
    extern HANDLE ghMemHeap;
    extern HANDLE ghCancelEvent;
    extern HWND ghTreeView, ghListView, ghWnd, ghStatusBar, ghToolBar;
    extern BOOL gfCancel, gfRPCinProgress;
    extern HFONT ghBoldFont;
    extern CRITICAL_SECTION csCancel;
    extern CRITICAL_SECTION csRemoteServer;
    extern TCHAR g_szCurrentServer[];
    extern HIMAGELIST g_hImages, g_hIconImgs;

    void WINAPI AddServerToList
                        (LPTSTR                     szServer,
                         BOOL                       fExpandRoot);

    void WINAPI CreateNewMailbox
                        (HWND                       hOwnerWnd);
    void WINAPI CreateNewDistList
                        (HWND                       hOwnerWnd);
    void WINAPI CreateNewPubFolder
                        (HWND                       hOwnerWnd);
    void WINAPI ShowMailboxProps
                        (HWND                       hOwnerWnd,
                         DWORD                      dwObjID);
    void WINAPI ShowDistListProps
                        (HWND                       hOwnerWnd,
                         DWORD                      dwObjID);
    void WINAPI DeleteServerObject
                        (HWND                       hOwnerWnd,
                         DWORD                      dwObjID);
    void WINAPI PurgeMailboxMessages
                        (HWND                       hOwnerWnd,
                         DWORD                      dwObjID);
    void WINAPI ErrorHandler
                        (HWND                       hOwnerWnd,
                         HRESULT                    hError);
    void WINAPI DrawListViewItem
                        (LPDRAWITEMSTRUCT           pDIS);
    void WINAPI UpdateHeaderWidth
                        (HWND                       hWndHeader,
                         int                        iItem);

    BOOL WINAPI CreateListView
                        (HWND                       hOwnerWnd,
                         HIMAGELIST                 hImages);
    BOOL WINAPI CreateTreeView
                        (HWND                       hOwnerWnd,
                         HIMAGELIST                 hImages);
    BOOL WINAPI CreateStatusBar
                        (HWND                       hOwnerWnd);
    BOOL WINAPI CreateToolBar
                        (HWND                       hOwnerWnd);
    BOOL WINAPI IsObjAliasValid
                        (HWND                       hOwnerWnd,
                         LPTSTR                     szObjAlias);

    HRESULT WINAPI BindToServer
                        (LPTSTR                     szServer);
    HRESULT WINAPI GetServerMailboxes
                        (HWND                       hOwnerWnd);
    HRESULT WINAPI GetServerDistLists
                        (HWND                       hOwnerWnd);
    HRESULT WINAPI DownloadBulkInfo
                        (HWND                       hOwnerWnd,
                         HWND                       hListView,
                         ITEM_TYPE                  Type);
    
    HCURSOR WINAPI GetAnimatedTimerCursor
                        ();

    BOOL WINAPI BrowseFileName
                        (HWND                       hOwnerWnd,
                         LPTSTR                     szFileName,
                         BOOL                       fImport);
    BOOL CALLBACK AboutDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK ServerConnectDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK ExportDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK ImportDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK ImportProgressDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK ExportProgressDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK RemoveServersDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
    BOOL CALLBACK SelectUserDlgProc
                        (HWND                       hDlg, 
                         UINT                       message, 
                         WPARAM                     wParam, 
                         LPARAM                     lParam);
};

inline BOOL WINAPI AbortRemoteCall()
{
    BOOL fState;
    EnterCriticalSection (&csCancel);
    fState = gfCancel;
    if (TRUE == gfCancel)
    {
        gfCancel = FALSE;
    }
    LeaveCriticalSection (&csCancel);
    return fState;
}

class CNotifLink;

extern CNotifLink * gpLink;

DWORD WINAPI MailslotListenThreadProc (CNotifLink * pLink);

class CNotifLink
{
public :
    STDMETHODIMP StartNotification
                        ();
    STDMETHODIMP EndNotifications
                        ();
    inline HANDLE WINAPI GetListenMailslot
                        () { return m_hMailSlot; }

public :
    CNotifLink();
    ~CNotifLink();

private :
    HANDLE      m_hMailSlot;
    ULONG       m_ulConnectionID;
    TCHAR       m_szComputerName[MAX_COMPUTERNAME_LENGTH + 1];
};

#endif // _WINDSADM_H

// End of file for WINDSADM.H
