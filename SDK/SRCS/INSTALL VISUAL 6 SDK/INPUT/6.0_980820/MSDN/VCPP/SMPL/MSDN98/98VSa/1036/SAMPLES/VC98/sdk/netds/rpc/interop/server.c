/*************************************************************/
/**                                                         **/
/**                 Microsoft RPC Examples                  **/
/**                 OSF DCE Interop Application             **/
/**           Copyright(c) Microsoft Corp. 1993-1996        **/
/**                                                         **/
/*************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "msg.h"    /* header file generated by M/IDL compiler */

#if defined(__RPC_WIN32__) || defined(__RPC_DOS__)

/*
 On MS platforms we must include the dceport.h header file
 which maps OSF DCE style APIs to MS style APIs.

 Currently, we must also define a common interface handle name.
*/

#include "dceport.h"

#else
#include <pthread.h>
#endif

#ifndef _CRTAPI1
#define _CRTAPI1
#endif

void Usage()
{
  printf("Usage : server -e <endpoint>   - optional endpoint\n");
  printf("               -t <transport>  - optional, default ncacn_ip_tcp\n");
  exit(1);
}

int _CRTAPI1
main(int argc, char *argv[])
{
    unsigned32 status;
    unsigned char * pszProtocolSequence = (unsigned char *)"ncacn_ip_tcp";
    unsigned char * pszEndpoint         = NULL;
    unsigned int    cMaxCalls           = 20;
    rpc_binding_vector_p_t pbvBindings  = NULL;
    int i;

    printf ("Microsoft RPC Demo - OSF DCE Interop Message Server\n");

    for (i = 1; i < argc; i++) {
        if ((*argv[i] == '-') || (*argv[i] == '/')) {
            switch (tolower(*(argv[i]+1))) {
            case 'e':
                pszEndpoint = (unsigned char *)argv[++i];
                break;
            case 't':
                pszProtocolSequence = (unsigned char *)argv[++i];
                break;
            case 'h':
            case '?':
            default:
                Usage();
            }
        }
        else
            Usage();
    }

    if (pszEndpoint != NULL)
        {
        /*
         Since we have an explict endpoint, use it and
         wait for client requests.
        */
        rpc_server_use_protseq_ep(pszProtocolSequence,
                                   cMaxCalls,
                                   pszEndpoint,
                                   &status);
        if (status) {
            printf("rpc_server_use_protseq_ep returned 0x%x\n", status);
            return status;
            }
        }
    else
        {
        /*
         No explict endpoint, use the protocol sequence and register
         the endpoint with the endpoint mapper.
        */
        rpc_server_use_protseq(pszProtocolSequence,
                               cMaxCalls,
                               &status);
        if (status) {
            printf("rpc_server_use_protseq returned 0x%x\n", status);
            return status;
            }

        rpc_server_inq_bindings(&pbvBindings, &status);
        if (status) {
            printf("rpc_server_inq_bindings returned 0x%x\n", status);
            return status;
            }

        rpc_ep_register(interop_v1_0_s_ifspec,
                        pbvBindings,
                        0,
                        0,
                        &status);
        if (status) {
            printf("rpc_ep_register returned 0x%x\n", status);
            return status;
            }
        }

    rpc_server_register_if(interop_v1_0_s_ifspec,
                           0,
                           0,
                           &status);
    if (status) {
        printf("rpc_server_register_if returned 0x%x\n", status);
        return status;
    }

    printf("RPC server ready\n");
    rpc_server_listen(cMaxCalls,&status);

    if (status) {
        printf("rpc_server_listen returned: 0x%x\n", status);
        return status;
    }

    rpc_server_unregister_if(interop_v1_0_s_ifspec,
                             0,
                             &status);
    if (status) {
        printf("rpc_server_unregister_if returned 0x%x\n", status);
        return status;
    }

    if (pszEndpoint == NULL)
        {
        /*
         Unregister from endpoint mapper
         */
        rpc_ep_unregister(interop_v1_0_s_ifspec,
                          pbvBindings,
                          0,
                          &status);
        if (status) {
            printf("rpc_ep_unregister returned 0x%x\n", status);
            return status;
            }

        rpc_binding_vector_free(&pbvBindings, &status);
        if (status) {
            printf("rpc_binding_vector_free returned 0x%x\n", status);
            return status;
            }
        }
}

