// mainfrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "dldetect.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_ASAMATRIX, OnViewAsamatrix)
	ON_COMMAND(ID_VIEW_ASANET, OnViewAsanet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
		ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
		ID_SEPARATOR,
	ID_FILE_PRINT,
	ID_APP_ABOUT,
};

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,			// status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadBitmap(IDR_MAINFRAME) ||
		!m_wndToolBar.SetButtons(buttons,
		  sizeof(buttons)/sizeof(UINT)))
	{
		TRACE("Failed to create toolbar\n");
		return -1;		// fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE("Failed to create status bar\n");
		return -1;		// fail to create
	}

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

void CMainFrame::CreateOrActivateFrame(CDocTemplate *pTemplate,
                                       CRuntimeClass *pViewClass)
{
 CMDIChildWnd *pMDIActive = MDIGetActive();
 CDocument *pDoc;
 if (pMDIActive != NULL)
  { pDoc = pMDIActive->GetActiveDocument();
    if (pDoc != NULL)
	   { CView *pView;
	     POSITION pos = pDoc->GetFirstViewPosition();
		 while (pos)
		 {
		   pView = pDoc->GetNextView(pos);
		   if (pView->IsKindOf(pViewClass))
		   {
		       pView->GetParentFrame()->ActivateFrame();
			   return;
		   }
		 }
	   }
  };
 pMDIActive= (CMDIChildWnd *)(pTemplate->CreateNewFrame(pDoc, NULL));
 if (pMDIActive == NULL) return;
 pTemplate->InitialUpdateFrame(pMDIActive, pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnViewAsamatrix()
{
	CreateOrActivateFrame(theApp.m_pMatrixTemplate, RUNTIME_CLASS(CMatrixView));
	
}

void CMainFrame::OnViewAsanet()
{
	CreateOrActivateFrame(theApp.m_pNetTemplate, RUNTIME_CLASS(CNetView));
	
}
