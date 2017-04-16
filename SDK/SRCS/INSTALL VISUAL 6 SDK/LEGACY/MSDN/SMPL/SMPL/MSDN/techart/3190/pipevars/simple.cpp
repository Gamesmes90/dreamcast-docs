#include "stdafx.h"
#include "comclass.h"

#include <windows.h>

#ifdef SECURITY

#include "sec.h"

#endif


#include "npipe.h"


// Buffers and pipe symbolic constants.
#define IN_BUF_SIZE        4096
#define OUT_BUF_SIZE       4096
#define TIME_OUT           INFINITE


  CClientNamedPipe::CClientNamedPipe() : CClientCommunication()
  {
   strcpy(m_szPipeEndNameIn,DEFAULTINPIPENAME);
   strcpy(m_szPipeEndNameOut,DEFAULTOUTPIPENAME);
   strcpy(m_szPipeEndNameBoth,DEFAULTBIPIPENAME);
   m_iStatusPending = STATUS_NOT_CONNECTED;

  };

  CClientNamedPipe::CClientNamedPipe(PSTR pIn, PSTR pOut, PSTR pBiDir) : CClientCommunication()
  {
   strcpy(m_szPipeEndNameIn,pIn);
   strcpy(m_szPipeEndNameOut,pOut);
   strcpy(m_szPipeEndNameBoth,pBiDir);
   m_iStatusPending = STATUS_NOT_CONNECTED;

  };


  CClientNamedPipe::~CClientNamedPipe()
  {
  };

  BOOL CClientNamedPipe::Open(const char* pszFileName, UINT nOpenFlags,
		CFileException* pError)
// currently we only support the READ and WRITE open flags...
  { 
    DWORD dwModeTypeClient = NULL;
    PSTR pName;
    if (nOpenFlags == modeReadWrite)  // bidirectional pipe
	{
	 dwModeTypeClient = GENERIC_READ|GENERIC_WRITE;
	 pName = m_szPipeEndNameBoth;
	}
	else 
	if (nOpenFlags == modeRead)
	{
	 dwModeTypeClient = GENERIC_READ;
	 pName = m_szPipeEndNameIn;
	}
	else  
	if (nOpenFlags == modeWrite)
	{
	 dwModeTypeClient = GENERIC_WRITE;
	 pName = m_szPipeEndNameOut;
	}
	else return FALSE;  // bad flags passed in

       if (!pszFileName) return FALSE;         // NULL means we want to be the server
       { 
       sprintf (m_szPipeName, "\\\\%s\\PIPE\\%s", pszFileName,pName);

                                       // Do CreateFile() to connect to the
                                       // named pipe.
       m_hFile = (UINT)CreateFile (m_szPipeName,              // Pipe name.
						           dwModeTypeClient, 
                             FILE_SHARE_READ        // Share both read and write.
                           | FILE_SHARE_WRITE ,
                           NULL,                  // No security.
                           OPEN_EXISTING,         // Fail if not existing.
                           FILE_ATTRIBUTE_NORMAL,  //
                           NULL);                 // No template.

                                       // Do some error checking.
       if ((HANDLE)m_hFile == INVALID_HANDLE_VALUE)
         {
		 m_iErrorCode=GetLastError();
         return FALSE;
		 };
	   m_bWeAreServer = FALSE;
      };

  return TRUE;
  };


void CClientNamedPipe::Close(void)
{	
 if (m_iStatusPending & STATUS_CONNECTED)
 {
  if (m_bWeAreServer) 
  {
   FlushFileBuffers((HANDLE)m_hFile);
   DisconnectNamedPipe((HANDLE)m_hFile);
  };
 };
 m_iStatusPending = STATUS_NOT_CONNECTED;
 CloseHandle((HANDLE)m_hFile);
};



void CClientNamedPipe::Write(const void FAR* pBuf, UINT iCount)
{
 unsigned long bytesSent;
 if (!WriteFile ((HANDLE)m_hFile, pBuf, iCount,&bytesSent, NULL))
 { DWORD dwErrorCode = GetLastError();
//	    if (dwErrorCode != ERROR_PIPE_NOT_CONNECTED)
   RaiseException(dwErrorCode,0,0,NULL);
 };
 };

UINT CClientNamedPipe::Read(void FAR* pBuf, UINT iCount)
{	
 unsigned long uReturn;
 BOOL bRetCode;
 bRetCode = ReadFile((HANDLE)m_hFile,pBuf,iCount,&uReturn,NULL);
 if (!bRetCode)
 { 
  DWORD dwErrorCode = GetLastError();  
//          if (dwErrorCode != ERROR_PIPE_NOT_CONNECTED)
  RaiseException(dwErrorCode,0,0,NULL);
  return 0;   // to shut the compiler up
 }
 else return uReturn;
};

BOOL CClientNamedPipe::ReConnect(void)
{	
 return FALSE;
};

// server end definition

CServerNamedPipe::CServerNamedPipe() : CClientNamedPipe()
{
};

CServerNamedPipe::CServerNamedPipe(PSTR pIn, PSTR pOut, PSTR pBiDir) : CClientNamedPipe(pIn,pOut,pBiDir)
{
};


BOOL CServerNamedPipe::Open(const char* pszFileName, UINT nOpenFlags,
		CFileException* pError)
// currently we only support the READ and WRITE open flags...
{
 m_iFlagsOpened = nOpenFlags; 
 DWORD dwModeType = NULL;
 PSTR pName;
 if (nOpenFlags == modeReadWrite)  // bidirectional pipe
 {
  dwModeType = PIPE_ACCESS_DUPLEX;
  pName = m_szPipeEndNameBoth;
 }
 else 
 if (nOpenFlags == modeRead)
 {
  dwModeType = PIPE_ACCESS_DUPLEX;  // we need this for SetNamedPipeHandleState!!!
  pName = m_szPipeEndNameOut;
 }
 else  
 if (nOpenFlags == modeWrite)
 {
  dwModeType = PIPE_ACCESS_DUPLEX; // we need this for GetNamedPipeHandleState!!!
  pName = m_szPipeEndNameIn;
 }
 else return FALSE;  // bad flags passed in
 if (pszFileName) return FALSE;         // NULL means we want to be the server	    
 sprintf(m_szPipeName,"\\\\.\\PIPE\\%s",pName); 
               m_hFile = (UINT)CreateNamedPipe (m_szPipeName,
               WRITE_DAC|
               dwModeType,
               PIPE_WAIT                         // Wait on messages.
               | PIPE_READMODE_MESSAGE           // Specify byte pipe.
               | PIPE_TYPE_MESSAGE,
               PIPE_UNLIMITED_INSTANCES,               // Maximum instance limit.
               OUT_BUF_SIZE,                     // Buffer sizes.
               IN_BUF_SIZE,
               TIME_OUT,                         // Specify time out.
			   NULL);
 if ((HANDLE)m_hFile == INVALID_HANDLE_VALUE)
 {
  m_iErrorCode=GetLastError();
  return FALSE;                          // flag is not set here. 
 };
 m_bWeAreServer = TRUE;
 return TRUE;
};

void CServerNamedPipe::Close(void)
{	
 if (m_iStatusPending & STATUS_CONNECTED)
 {
  FlushFileBuffers((HANDLE)m_hFile);
  DisconnectNamedPipe((HANDLE)m_hFile);
 };
 m_iStatusPending = STATUS_NOT_CONNECTED;
 CloseHandle((HANDLE)m_hFile);
};


BOOL CServerNamedPipe::AwaitCommunicationAttempt(void)
{
   m_iStatusPending = STATUS_CONNECTION_PENDING;
   m_bNotCancelled = TRUE;
   ConnectNamedPipe((HANDLE)m_hFile, NULL);
   if (m_bNotCancelled)
   {
    m_iStatusPending = STATUS_CONNECTED;
	return TRUE;
   };
   m_iStatusPending = STATUS_NOT_CONNECTED;
   m_iErrorCode = ERROR_REQUEST_ABORTED;
   return FALSE;
};

BOOL CServerNamedPipe::CancelCommunicationAttempt()
{
m_bNotCancelled = FALSE;
BOOL bReturn = FALSE;
CClientCommunication *csTerminator = new CClientNamedPipe(m_szPipeEndNameIn,m_szPipeEndNameOut,m_szPipeEndNameBoth);
UINT iFlags = (m_iFlagsOpened == modeRead)? modeWrite :
             ((m_iFlagsOpened == modeWrite) ? modeRead : modeReadWrite);
bReturn = csTerminator->Open(".",iFlags);
csTerminator->Close();
delete csTerminator;
return bReturn;
};

void CServerNamedPipe::CloseInstance()
{
 FlushFileBuffers((HANDLE)m_hFile);
 DisconnectNamedPipe((HANDLE)m_hFile);
 m_iStatusPending = STATUS_NOT_CONNECTED;
};

CServerCommunication *CServerNamedPipe::Duplicate() 
{ HANDLE hNewHandle;
  CServerNamedPipe *cnpReturn = new(CServerNamedPipe);
 if (DuplicateHandle(GetCurrentProcess(),(HANDLE)m_hFile,
                    GetCurrentProcess(),&hNewHandle,NULL,FALSE,DUPLICATE_SAME_ACCESS))
   {
    cnpReturn->m_hFile = (UINT) hNewHandle;
    cnpReturn->m_bWeAreServer = m_bWeAreServer;
    cnpReturn->cOtherMachineName = cOtherMachineName;
    cnpReturn->m_iMode = m_iMode;
	cnpReturn->m_iStatusPending = m_iStatusPending;
	return cnpReturn;
   };
 return (CServerCommunication *)NULL;
}


#ifdef SECURITY

BOOL CSecuredNamedPipe::SetTheDescriptor()
{
 if (m_iStatusPending == STATUS_CONNECTION_PENDING)
 {
  m_iErrorCode = ERROR_PIPE_BUSY;
  return FALSE;       // we can't set the security while a connection is pending...
 };
 return (SetObjectSecurity((HANDLE)m_hFile));
};

BOOL CSecuredNamedPipe::GetTheDescriptor()
{
 if (m_iStatusPending == STATUS_CONNECTION_PENDING)
 {
  m_iErrorCode = ERROR_PIPE_BUSY;
  return FALSE;       // we can't set the security while a connection is pending...
 };
 return (GetObjectSecurity((HANDLE)m_hFile));
};


BOOL CSecuredNamedPipe::ImpersonateClient(BOOL bParam)
{
 if (bParam)
  return ImpersonateNamedPipeClient((HANDLE)m_hFile);
 else return RevertToSelf();
};

BOOL CSecuredNamedPipe::Open(const char* pszFileName, UINT nOpenFlags,CFileException* pError)
{
 if (!CServerNamedPipe::Open(pszFileName,nOpenFlags,pError)) // must resolve ambiguity here
   return FALSE;
 if (!SetTheDescriptor()) return FALSE;
 return TRUE;
}

#endif SECURITY
