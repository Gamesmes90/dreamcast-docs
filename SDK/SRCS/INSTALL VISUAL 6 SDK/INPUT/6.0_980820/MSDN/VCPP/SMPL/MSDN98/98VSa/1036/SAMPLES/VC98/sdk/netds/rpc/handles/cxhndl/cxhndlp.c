/****************************************************************************
                   Microsoft RPC Version 2.0
           Copyright Microsoft Corp. 1992, 1993, 1994- 1996
                        cxhndl Example

    FILE:       cxhndlp.c

    PURPOSE:    Remote procedures used in server application cxhndls

    FUNCTIONS:  RemoteOpen() - Open the file
                RemoteRead() - Read a buffer's worth of the file
                RemoteClose() - Close the file and shutdown server
                Shutdown() - Shutdown the server

    COMMENTS:   This distributed application uses a context handle.

****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cxhndl.h"    // header file generated by MIDL compiler


typedef struct {
    FILE *hFile;
    char achFile[256];
} FILE_CONTEXT_TYPE;


/* This remote procedure opens a file on the server. */
short RemoteOpen(PCONTEXT_HANDLE_TYPE  *pphContext,
                 unsigned char         *pszFileName
    )
{
    FILE *hFile;
    FILE_CONTEXT_TYPE *pFileContext;

    if ((hFile = fopen(pszFileName, "r")) == NULL) {
        *pphContext = (PCONTEXT_HANDLE_TYPE) NULL;
        return(-1);
    }
    else {
        pFileContext = (FILE_CONTEXT_TYPE *)
                       midl_user_allocate(sizeof(FILE_CONTEXT_TYPE));
        pFileContext->hFile = hFile;
        strcpy(pFileContext->achFile, pszFileName);
        *pphContext = (PCONTEXT_HANDLE_TYPE) pFileContext;
        return(0);
    }
}

/* This remote procedure reads a file on the server. */
short RemoteRead(PCONTEXT_HANDLE_TYPE  phContext,
                 unsigned char         *pbBuf,
                 short                 *pcbBuf)
{
    FILE_CONTEXT_TYPE *pFileContext;

    printf("in RemoteRead\n");

    pFileContext = (FILE_CONTEXT_TYPE *) phContext;
    *pcbBuf = (short) fread(pbBuf,
                            sizeof(char),
                            BUFSIZE,
                            pFileContext->hFile);
    return(*pcbBuf);
}

/* This remote procedure closes a file on the server. */
short RemoteClose(PCONTEXT_HANDLE_TYPE *pphContext)
{
    FILE_CONTEXT_TYPE *pFileContext;

    printf("in RemoteClose\n");

    pFileContext = (FILE_CONTEXT_TYPE *) *pphContext;

    if ( fclose( pFileContext->hFile ) == 0)
        {
        midl_user_free( *pphContext );
        *pphContext = NULL;
        return(0);
        }
    else
        /* Context Rundown routine will attempt to close it again */
        return(-1);
}

/* The Shutdown procedure tells the server to stop listening */
/* for client requests.                                      */
void Shutdown(void)
{
    RPC_STATUS status;

    printf("Calling RpcMgmtStopServerListening\n");
    status = RpcMgmtStopServerListening(NULL);
    printf("RpcMgmtStopServerListening returned: 0x%x\n", status);
    if (status) {
        exit(status);
    }

    printf("Calling RpcServerUnregisterIf\n");
    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    printf("RpcServerUnregisterIf returned 0x%x\n", status);
    if (status) {
        exit(status);
    }
}

/* The rundown routine is associated with the context handle type. */
void __RPC_USER PCONTEXT_HANDLE_TYPE_rundown(PCONTEXT_HANDLE_TYPE phContext)
{
    FILE_CONTEXT_TYPE *pFileContext;

    printf("Context rundown routine\n");

    if ( phContext )
    {
        pFileContext = (FILE_CONTEXT_TYPE *) phContext;
        if (pFileContext->hFile != NULL)
            fclose(pFileContext->hFile);

        midl_user_free( phContext );
    }

}

/* end file cxhndlp.c */
