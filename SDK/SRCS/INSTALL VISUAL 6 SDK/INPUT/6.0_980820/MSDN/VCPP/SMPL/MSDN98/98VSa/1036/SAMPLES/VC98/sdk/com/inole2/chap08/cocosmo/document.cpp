/*
 * DOCUMENT.CPP
 * Component Cosmo Chapter 8
 *
 * Implementation of the CCosmoDoc derivation of CDocument as
 * well as an implementation of CPolylineAdviseSink.
 *
 * Copyright (c)1993-1995 Microsoft Corporation, All Rights Reserved
 *
 * Kraig Brockschmidt, Microsoft
 * Internet  :  kraigb@microsoft.com
 * Compuserve:  >INTERNET:kraigb@microsoft.com
 */


#include "cocosmo.h"


/*
 * CCosmoDoc::CCosmoDoc
 * CCosmoDoc::~CCosmoDoc
 *
 * Constructor Parameters:
 *  hInst           HINSTANCE of the application.
 *  pFR             PCFrame of the frame object.
 *  pAdv            PCDocumentAdviseSink to notify on events
 */

CCosmoDoc::CCosmoDoc(HINSTANCE hInst, PCFrame pFR
    , PCDocumentAdviseSink pAdv)
    : CDocument(hInst, pFR, pAdv)
    {
    m_pPL=NULL;
    m_pPLAdv=NULL;
    m_uPrevSize=SIZE_RESTORED;
    m_pIConnectPt=NULL;
    m_dwCookie=0;

    //CHAPTER8MOD
    m_pIStorage=NULL;
    m_pp.psModel=PERSIST_UNKNOWN;
    m_pp.pIP.pIPersistStorage=NULL; //Affects all pointers
    //End CHAPTER8MOD
    return;
    }


CCosmoDoc::~CCosmoDoc(void)
    {
    //CHAPTER8MOD
    ReleaseInterface(m_pp.pIP.pIPersistStorage);
    ReleaseInterface(m_pIStorage);
    //End CHAPTER8MOD

    if (NULL!=m_pIConnectPt)
        {
        m_pIConnectPt->Unadvise(m_dwCookie);
        ReleaseInterface(m_pIConnectPt);
        }

    ReleaseInterface(m_pPL);
    ReleaseInterface(m_pPLAdv);

    CoFreeUnusedLibraries();
    return;
    }






/*
 * CCosmoDoc::Init
 *
 * Purpose:
 *  Initializes an already created document window.  The client
 *  actually creates the window for us, then passes that here for
 *  further initialization.
 *
 * Parameters:
 *  pDI             PDOCUMENTINIT containing initialization
 *                  parameters.
 *
 * Return Value:
 *  BOOL            TRUE if the function succeeded, FALSE otherwise.
 */

BOOL CCosmoDoc::Init(PDOCUMENTINIT pDI)
    {
    RECT                        rc;
    HRESULT                     hr;
    IConnectionPointContainer  *pCPC;

    //Change the stringtable range to our customization.
    pDI->idsMin=IDS_DOCUMENTMIN;
    pDI->idsMax=IDS_DOCUMENTMAX;

    //Do default initialization
    if (!CDocument::Init(pDI))
        return FALSE;

    //CHAPTER8MOD
    //Create the Polyline component
    hr=CoCreateInstance(CLSID_Polyline8, NULL, CLSCTX_INPROC_SERVER
        , IID_IPolyline8, (PPVOID)&m_pPL);
    //End CHAPTER8MOD

    if (FAILED(hr))
        {
        //Warn that we could not load the Polyline
        MessageBox(pDI->hWndDoc, PSZ(IDS_NOPOLYLINE)
            , PSZ(IDS_CAPTION), MB_OK);
        return FALSE;
        }

    //Initialize the contained Polyline which creates a window.
    GetClientRect(m_hWnd, &rc);
    InflateRect(&rc, -8, -8);

    if (FAILED(m_pPL->Init(m_hWnd, &rc, WS_CHILD | WS_VISIBLE
        , ID_POLYLINE)))
        return FALSE;

    //Set up an advise on the Polyline.
    m_pPLAdv=new CPolylineAdviseSink(this);
    m_pPLAdv->AddRef();

    if (SUCCEEDED(m_pPL->QueryInterface(IID_IConnectionPointContainer
        , (PPVOID)&pCPC)))
        {
        //CHAPTER8MOD
        if (SUCCEEDED(pCPC->FindConnectionPoint
            (IID_IPolylineAdviseSink8, &m_pIConnectPt)))
        //End CHAPTER8MOD
            {
            m_pIConnectPt->Advise((LPUNKNOWN)m_pPLAdv, &m_dwCookie);
            }

        pCPC->Release();
        }

    //CHAPTER8MOD
    /*
     * Check for the storage model being used in Polyline.
     * Any InitNew member will be called from CCosmoDoc::Load.
     */
    hr=m_pPL->QueryInterface(IID_IPersistStorage
        , (PPVOID)&m_pp.pIP.pIPersistStorage);

    if (SUCCEEDED(hr))
        m_pp.psModel=PERSIST_STORAGE;
    else
        {
        hr=m_pPL->QueryInterface(IID_IPersistStreamInit
            , (PPVOID)&m_pp.pIP.pIPersistStreamInit);

        if (SUCCEEDED(hr))
            m_pp.psModel=PERSIST_STREAMINIT;
        else
            {
            hr=m_pPL->QueryInterface(IID_IPersistStream
            , (PPVOID)&m_pp.pIP.pIPersistStream);

            if (SUCCEEDED(hr))
                m_pp.psModel=PERSIST_STREAM;
            else
                return FALSE;
            }
        }

    //End CHAPTER8MOD

    return TRUE;
    }







/*
 * CCosmoDoc::FMessageHook
 *
 * Purpose:
 *  Processes WM_SIZE for the document so we can resize
 *  the Polyline.
 *
 * Parameters:
 *  <WndProc Parameters>
 *  pLRes           LRESULT * in which to store the return
 *                  value for the message.
 *
 * Return Value:
 *  BOOL            TRUE to prevent further processing,
 *                  FALSE otherwise.
 */

BOOL CCosmoDoc::FMessageHook(HWND hWnd, UINT iMsg, WPARAM wParam
    , LPARAM lParam, LRESULT *pLRes)
    {
    UINT        dx, dy;
    RECT        rc;

    *pLRes=0;

    if (WM_SIZE==iMsg)
        {
        //Don't effect the Polyline size to or from minimized state.
        if (SIZE_MINIMIZED!=wParam && SIZE_MINIMIZED !=m_uPrevSize)
            {
            //When we change size, resize any Polyline we hold.
            dx=LOWORD(lParam);
            dy=HIWORD(lParam);

            /*
             * If we are getting WM_SIZE in response to a Polyline
             * notification, then don't resize the Polyline window
             * again.
             */
            if (!m_fNoSize && NULL!=m_pPL)
                {
                //Resize the polyline to fit the new client
                SetRect(&rc, 8, 8, dx-8, dy-8);
                m_pPL->RectSet(&rc, FALSE);

                /*
                 * We consider sizing something that makes the file
                 * dirty, but not until we've finished the create
                 * process, which is why we set fNoDirty to FALSE
                 * in WM_CREATE since we get a WM_SIZE on the first
                 * creation.
                 */
                if (!m_fNoDirty)
                    FDirtySet(TRUE);

                SetRect(&rc, 0, 0, dx, dy);

                if (NULL!=m_pAdv)
                    m_pAdv->OnSizeChange(this, &rc);

                m_fNoDirty=FALSE;
                }
            }

        m_uPrevSize=wParam;
        }

    /*
     * We return FALSE even on WM_SIZE so we can let the default
     * procedure handle maximized MDI child windows appropriately.
     */
    return FALSE;
    }








/*
 * CCosmoDoc::Clear
 *
 * Purpose:
 *  Sets all contents in the document back to defaults with
 *  no filename.
 *
 * Paramters:
 *  None
 *
 * Return Value:
 *  None
 */

void CCosmoDoc::Clear(void)
    {
    //Completely reset the polyline
    m_pPL->New();

    CDocument::Clear();
    return;
    }






/*
 * CCosmoDoc::Load
 *
 * Purpose:
 *  Loads a given document without any user interface overwriting
 *  the previous contents of the Polyline window.  We do this by
 *  opening the file and telling the Polyline to load itself from
 *  that file.
 *
 * Parameters:
 *  fChangeFile     BOOL indicating if we're to update the window
 *                  title and the filename from using this file.
 *  pszFile         LPTSTR to the filename to load, NULL if the file
 *                  is new and untitled.
 *
 * Return Value:
 *  UINT            An error value from DOCERR_*
 */

UINT CCosmoDoc::Load(BOOL fChangeFile, LPTSTR pszFile)
    {
    HRESULT             hr;
    //CHAPTER8MOD
    LPSTORAGE           pIStorage;

    if (NULL==pszFile)
        {
        //CHAPTER8MOD
        /*
         * As a user of an IPersistStorage we have to provide all
         * objects with an IStorage they can use for incremental
         * access passing that storage to InitNew.  Here we create
         * a temporary file that we don't bother holding on to.
         * If the object doesn't use it, then our Release destroys
         * it immediately.
         */

        hr=StgCreateDocfile(NULL, STGM_DIRECT | STGM_READWRITE
            | STGM_CREATE | STGM_DELETEONRELEASE
            | STGM_SHARE_EXCLUSIVE, 0, &pIStorage);

        if (FAILED(hr))
            return DOCERR_COULDNOTOPEN;

        if (PERSIST_STORAGE==m_pp.psModel)
            m_pp.pIP.pIPersistStorage->InitNew(pIStorage);
        else
            {
            if (PERSIST_STREAMINIT==m_pp.psModel)
                m_pp.pIP.pIPersistStreamInit->InitNew();
            }

        m_pIStorage=pIStorage;
        //End CHAPTER8MOD

        Rename(NULL);
        return DOCERR_NONE;
        }

    //CHAPTER8MOD
    /*
     * Open a storage and have the Polyline read its data
     * using whatever persistence model it employs.
     */
    hr=StgOpenStorage(pszFile, NULL, STGM_DIRECT | STGM_READWRITE
        | STGM_SHARE_EXCLUSIVE, NULL, 0, &pIStorage);

    if (FAILED(hr))
        return DOCERR_COULDNOTOPEN;

    if (PERSIST_STORAGE==m_pp.psModel)
        hr=m_pp.pIP.pIPersistStorage->Load(pIStorage);
    else
        {
        LPSTREAM    pIStream;

        hr=pIStorage->OpenStream(SZSTREAM, 0, STGM_DIRECT
            | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, &pIStream);

        if (SUCCEEDED(hr))
            {
            //This also works for PERSIST_STREAMINIT
            hr=m_pp.pIP.pIPersistStream->Load(pIStream);
            pIStream->Release();
            }
        }

    m_pIStorage=pIStorage;
    //End CHAPTER8MOD

    if (FAILED(hr))
        return DOCERR_READFAILURE;

    if (fChangeFile)
        Rename(pszFile);

    //Importing a file makes things dirty
    FDirtySet(!fChangeFile);

    return DOCERR_NONE;
    }







/*
 * CCosmoDoc::Save
 *
 * Purpose:
 *  Writes the file to a known filename, requiring that the user
 *  has previously used FileOpen or FileSaveAs in order to have
 *  a filename.
 *
 * Parameters:
 *  uType           UINT indicating the type of file the user
 *                  requested to save in the File Save As dialog.
 *  pszFile         LPTSTR under which to save.  If NULL, use the
 *                  current name.
 *
 * Return Value:
 *  UINT            An error value from DOCERR_*
 */

UINT CCosmoDoc::Save(UINT uType, LPTSTR pszFile)
    {
    BOOL                fRename=TRUE;
    HRESULT             hr;
    //CHAPTER8MOD
    LPSTORAGE           pIStorage;
    BOOL                fSameAsLoad;

    //If Save or Save As under the same name, do Save.
    if (NULL==pszFile || 0==lstrcmpi(pszFile, m_szFile))
        {
        fRename=FALSE;
        pszFile=m_szFile;

        /*
         * If we're saving to an existing storage, just pass
         * the IStorage we have from Load along with TRUE
         * in fSameAsLoad.
         */
        fSameAsLoad=TRUE;
        }
    else
        {
        /*
         * In Component Cosmo, we only deal with one version of
         * data; all the code in Chapter 1 Cosmo that dealt with
         * 1.0 and 2.0 files has been removed.
         */

        hr=StgCreateDocfile(pszFile, STGM_DIRECT | STGM_READWRITE
            | STGM_CREATE | STGM_SHARE_EXCLUSIVE, 0, &pIStorage);

        if (FAILED(hr))
            return DOCERR_COULDNOTOPEN;

        //Tell the object to save into this new storage
        fSameAsLoad=FALSE;

        //Update our variable
        m_pIStorage->Release();
        m_pIStorage=pIStorage;
        }

    if (PERSIST_STORAGE==m_pp.psModel)
        {
        hr=m_pp.pIP.pIPersistStorage->Save(m_pIStorage, fSameAsLoad);

        if (SUCCEEDED(hr))
            {
            hr=m_pp.pIP.pIPersistStorage->SaveCompleted(fSameAsLoad
                ? NULL : m_pIStorage);
            }
        }
    else
        {
        LPSTREAM    pIStream;

        hr=m_pIStorage->CreateStream(SZSTREAM, STGM_DIRECT
            | STGM_CREATE | STGM_WRITE | STGM_SHARE_EXCLUSIVE
            , 0, 0, &pIStream);

        if (SUCCEEDED(hr))
            {
            //This also works for PERSIST_STREAMINIT
            hr=m_pp.pIP.pIPersistStream->Save(pIStream, TRUE);
            pIStream->Release();
            }
        }
    //End CHAPTER8MOD

    if (FAILED(hr))
        return DOCERR_WRITEFAILURE;

    //Saving makes us clean
    FDirtySet(FALSE);

    if (fRename)
        Rename(pszFile);

    return DOCERR_NONE;
    }






/*
 * CCosmoDoc::Undo
 *
 * Purpose:
 *  Reverses a previous action.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

void CCosmoDoc::Undo(void)
    {
    m_pPL->Undo();
    return;
    }






/*
 * CCosmoDoc::Clip
 *
 * Purpose:
 *  Places a private format, a metafile, and a bitmap of the display
 *  on the clipboard, optionally implementing Cut by deleting the
 *  data in the current window after rendering.
 *
 * Parameters:
 *  hWndFrame       HWND of the main window.
 *  fCut            BOOL indicating cut (TRUE) or copy (FALSE).
 *
 * Return Value:
 *  BOOL            TRUE if successful, FALSE otherwise.
 */

BOOL CCosmoDoc::Clip(HWND hWndFrame, BOOL fCut)
    {
    BOOL            fRet=TRUE;
    HGLOBAL         hMem;
    UINT            i;

    //This array is so we can loop over the formats we provide.
    static UINT     rgcf[3]={0, CF_METAFILEPICT, CF_BITMAP};
    const UINT      cFormats=3;

    if (!OpenClipboard(hWndFrame))
        return FALSE;

    //Clean out whatever junk is in the clipboard.
    EmptyClipboard();

    rgcf[0]=m_cf;

    for (i=0; i < cFormats; i++)
        {
        //Copy private data first.
        hMem=RenderFormat(rgcf[i]);

        if (NULL!=hMem)
            SetClipboardData(rgcf[i], hMem);
        else
            fRet &=FALSE;
        }

    //Free clipboard ownership.
    CloseClipboard();

    //Delete our current data if copying succeeded.
    if (fRet && fCut)
        {
        m_pPL->New();
        FDirtySet(TRUE);
        }

    return fRet;
    }





/*
 * CCosmoDoc::RenderFormat
 *
 * Purpose:
 *  Renders a specific clipboard format into global memory.
 *
 * Parameters:
 *  cf              UINT format to render.
 *
 * Return Value:
 *  HGLOBAL         Global memory handle containing the data.
 */

HGLOBAL CCosmoDoc::RenderFormat(UINT cf)
    {
    HGLOBAL     hMem;

    if (cf==m_cf)
        {
        m_pPL->DataGetMem(&hMem);
        return hMem;
        }

    switch (cf)
        {
        case CF_METAFILEPICT:
            m_pPL->RenderMetafilePict(&hMem);
            return hMem;

        case CF_BITMAP:
            m_pPL->RenderBitmap((HBITMAP *)&hMem);
            return hMem;
        }

    return NULL;
    }







/*
 * CCosmoDoc::FQueryPaste
 *
 * Purpose:
 *  Determines if we can paste data from the clipboard.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  BOOL            TRUE if data is available, FALSE otherwise.
 */

BOOL CCosmoDoc::FQueryPaste(void)
    {
    return IsClipboardFormatAvailable(m_cf);
    }





/*
 * CCosmoDoc::Paste
 *
 * Purpose:
 *  Retrieves the private data format from the clipboard and sets it
 *  to the current figure in the editor window.
 *
 *  Note that if this function is called, then the clipboard format
 *  is available because the Paste menu item is only enabled if the
 *  format is present.
 *
 * Parameters:
 *  hWndFrame       HWND of the main window.
 *
 * Return Value:
 *  BOOL            TRUE if successful, FALSE otherwise.
 */

BOOL CCosmoDoc::Paste(HWND hWndFrame)
    {
    HGLOBAL         hMem;
    PPOLYLINEDATA   ppl;
    BOOL            fRet=FALSE;

    if (!OpenClipboard(hWndFrame))
        return FALSE;

    hMem=GetClipboardData(m_cf);

    if (NULL!=hMem)
        {
        ppl=(PPOLYLINEDATA)GlobalLock(hMem);

        //TRUE in wParam to cause PLN_SIZECHANGE notification
        m_pPL->DataSet(ppl, FALSE, TRUE);
        GlobalUnlock(hMem);

        FDirtySet(TRUE);
        fRet=TRUE;
        }

    CloseClipboard();
    return fRet;
    }






/*
 * CCosmoDoc::ColorSet
 *
 * Purpose:
 *  Changes a color used in our contained Polyline.
 *
 * Parameters:
 *  iColor          UINT index of the color to change.
 *  cr              COLORREF new color.
 *
 * Return Value:
 *  COLORREF        Previous color for the given index.
 */

COLORREF CCosmoDoc::ColorSet(UINT iColor, COLORREF cr)
    {
    COLORREF    crRet;

    m_pPL->ColorSet(iColor, cr, &crRet);
    return crRet;
    }





/*
 * CCosmoDoc::ColorGet
 *
 * Purpose:
 *  Retrieves a color currently in use in the Polyline.
 *
 * Parameters:
 *  iColor          UINT index of the color to retrieve.
 *
 * Return Value:
 *  COLORREF        Current color for the given index.
 */

COLORREF CCosmoDoc::ColorGet(UINT iColor)
    {
    COLORREF    crRet;

    m_pPL->ColorGet(iColor, &crRet);
    return crRet;
    }






/*
 * CCosmoDoc::LineStyleSet
 *
 * Purpose:
 *  Changes the line style currently used in the Polyline
 *
 * Parameters:
 *  iStyle          UINT index of the new line style to use.
 *
 * Return Value:
 *  UINT            Previous line style.
 */

UINT CCosmoDoc::LineStyleSet(UINT iStyle)
    {
    UINT    i;

    m_pPL->LineStyleSet(iStyle, &i);
    return i;
    }







/*
 * CCosmoDoc::LineStyleGet
 *
 * Purpose:
 *  Retrieves the line style currently used in the Polyline
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  UINT            Current line style.
 */


UINT CCosmoDoc::LineStyleGet(void)
    {
    UINT    i=0;

    //m_pPL might not be valid yet.
    if (NULL!=m_pPL)
        m_pPL->LineStyleGet(&i);

    return i;
    }







/*
 * CPolylineAdviseSink::CPolylineAdviseSink
 * CPolylineAdviseSink::~CPolylineAdviseSink
 *
 * Constructor Parameters:
 *  pDoc            PCCosmoDoc to store in this object
 */

CPolylineAdviseSink::CPolylineAdviseSink(PCCosmoDoc pDoc)
    {
    m_pDoc=pDoc;
    m_cRef=0;
    AddRef();
    return;
    }


CPolylineAdviseSink::~CPolylineAdviseSink(void)
    {
    return;
    }




/*
 * CPolylineAdviseSink::QueryInterface
 * CPolylineAdviseSink::AddRef
 * CPolylineAdviseSink::Release
 *
 * Purpose:
 *  IUnknown members for this IPolylineAdviseSink implementations.
 */

STDMETHODIMP CPolylineAdviseSink::QueryInterface(REFIID riid
    , PPVOID ppv)
    {
    *ppv=NULL;

    //CHAPTER8MOD
    if (IID_IUnknown==riid || IID_IPolylineAdviseSink8==riid)
        *ppv=this;
    //End CHAPTER8MOD

    if (NULL!=*ppv)
        {
        ((LPUNKNOWN)*ppv)->AddRef();
        return NOERROR;
        }

    return ResultFromScode(S_FALSE);
    }


STDMETHODIMP_(ULONG) CPolylineAdviseSink::AddRef(void)
    {
    return ++m_cRef;
    }


STDMETHODIMP_(ULONG) CPolylineAdviseSink::Release(void)
    {
    if (0L!=--m_cRef)
        return m_cRef;

    delete this;
    return 0;
    }




/*
 * CPolylineAdviseSink::OnPointChange
 *
 * Purpose:
 *  Informs the document that the polyline added or removed a point.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CPolylineAdviseSink::OnPointChange(void)
    {
    m_pDoc->FDirtySet(TRUE);
    return;
    }






/*
 * CPolylineAdviseSink::OnSizeChange
 *
 * Purpose:
 *  Informs the document that the polyline changed size.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CPolylineAdviseSink::OnSizeChange(void)
    {
    RECT            rc;
    DWORD           dwStyle;
    HWND            hWnd;

    /*
     * Polyline window is informing us that it changed size in
     * response to setting it's data.  Therefore we have to
     * size ourselves accordingly but without moving the screen
     * position of the polyline window.
     */

    m_pDoc->m_fNoSize=TRUE;

    //Set the document window size.
    m_pDoc->m_pPL->Window(&hWnd);
    GetWindowRect(hWnd, &rc);
    InflateRect(&rc, 8, 8);

    //Adjust for a window sans menu
    dwStyle=GetWindowLong(m_pDoc->m_hWnd, GWL_STYLE);
    AdjustWindowRect(&rc, dwStyle, FALSE);

    SetWindowPos(m_pDoc->m_hWnd, NULL, 0, 0, rc.right-rc.left
        , rc.bottom-rc.top, SWP_NOMOVE | SWP_NOZORDER);

    if (NULL!=m_pDoc->m_pAdv)
        m_pDoc->m_pAdv->OnSizeChange(m_pDoc, &rc);

    m_pDoc->m_fNoSize=FALSE;
    m_pDoc->FDirtySet(TRUE);

    return;
    }





/*
 * CPolylineAdviseSink::OnDataChange
 *
 * Purpose:
 *  Informs the document that the polyline data changed.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CPolylineAdviseSink::OnDataChange(void)
    {
    if (NULL!=m_pDoc->m_pAdv)
        m_pDoc->m_pAdv->OnDataChange(m_pDoc);

    m_pDoc->FDirtySet(TRUE);
    return;
    }





/*
 * CPolylineAdviseSink::OnColorChange
 *
 * Purpose:
 *  Informs the document that the polyline data changed a color.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CPolylineAdviseSink::OnColorChange(void)
    {
    m_pDoc->FDirtySet(TRUE);
    return;
    }





/*
 * CPolylineAdviseSink::OnLineStyleChange
 *
 * Purpose:
 *  Informs the document that the polyline changed its line style.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CPolylineAdviseSink::OnLineStyleChange(void)
    {
    m_pDoc->FDirtySet(TRUE);
    return;
    }