// Appliances.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Appliances.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppliancesApp

BEGIN_MESSAGE_MAP(CAppliancesApp, CWinApp)
	//{{AFX_MSG_MAP(CAppliancesApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppliancesApp construction

CAppliancesApp::CAppliancesApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAppliancesApp object

CAppliancesApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAppliancesApp initialization

BOOL CAppliancesApp::InitInstance()
{
	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// Special entry points required for inproc servers

#if (_MFC_VER >= 0x300)
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow(void)
{
	return AfxDllCanUnloadNow();
}
#endif

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	COleObjectFactory::UpdateRegistryAll();
	return S_OK;
}
