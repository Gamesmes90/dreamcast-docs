/****************************************************************************
                   Microsoft RPC Version 2.0
           Copyright Microsoft Corp. 1992, 1993, 1994- 1996
                        Auto Example

    FILE:       autop.c

    PURPOSE:    Remote procedures that are linked with the server
                side of RPC distributed application

    FUNCTIONS:  TimeProc() - obtains the time from the server

    COMMENTS:   This distributed application uses an auto handle.

****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "auto.h"    // header file generated by MIDL compiler

void GetTime(time_t * pTime)
{
    time(pTime);
    return;
}

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

/* end file autop.c */
