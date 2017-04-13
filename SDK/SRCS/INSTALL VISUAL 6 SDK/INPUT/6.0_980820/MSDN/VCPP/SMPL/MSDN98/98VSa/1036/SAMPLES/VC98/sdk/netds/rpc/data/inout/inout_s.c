/* this ALWAYS GENERATED file contains the RPC server stubs */


/* File created by MIDL compiler version 3.03.0110 */
/* at Mon Mar 30 03:05:44 1998
 */
/* Compiler settings for inout.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include <string.h>
#include "inout.h"

#define TYPE_FORMAT_STRING_SIZE   9                                 
#define PROC_FORMAT_STRING_SIZE   15                                

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;

extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

/* Standard interface: inout, ver. 1.0,
   GUID={0x6E3B5060,0xCA46,0x1067,{0xB3,0x1A,0x00,0xDD,0x01,0x06,0x62,0xDA}} */


extern RPC_DISPATCH_TABLE inout_DispatchTable;

static const RPC_SERVER_INTERFACE inout___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x6E3B5060,0xCA46,0x1067,{0xB3,0x1A,0x00,0xDD,0x01,0x06,0x62,0xDA}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &inout_DispatchTable,
    0,
    0,
    0,
    0,
    0
    };
RPC_IF_HANDLE inout_ServerIfHandle = (RPC_IF_HANDLE)& inout___RpcServerInterface;

extern const MIDL_STUB_DESC inout_StubDesc;

void __RPC_STUB
inout_InOutProc(
    PRPC_MESSAGE _pRpcMessage )
{
    float _M0;
    MIDL_STUB_MESSAGE _StubMsg;
    float __RPC_FAR *pf3;
    short __RPC_FAR *ps2;
    short s1;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &inout_StubDesc);
    
    ( short __RPC_FAR * )ps2 = 0;
    ( float __RPC_FAR * )pf3 = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        s1 = *(( short __RPC_FAR * )_StubMsg.Buffer)++;
        
        ps2 = ( short __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( short  );
        
        pf3 = &_M0;
        
        InOutProc(
             s1,
             ps2,
             pf3);
        
        _StubMsg.BufferLength = 2U + 6U;
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        *(( short __RPC_FAR * )_StubMsg.Buffer)++ = *ps2;
        
        _StubMsg.Buffer += 2;
        *(( float __RPC_FAR * )_StubMsg.Buffer)++ = *pf3;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
inout_Shutdown(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &inout_StubDesc);
    
    RpcTryFinally
        {
        
        Shutdown();
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


static const MIDL_STUB_DESC inout_StubDesc = 
    {
    (void __RPC_FAR *)& inout___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x303006e, /* MIDL Version 3.3.110 */
    0,
    0,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static RPC_DISPATCH_FUNCTION inout_table[] =
    {
    inout_InOutProc,
    inout_Shutdown,
    0
    };
RPC_DISPATCH_TABLE inout_DispatchTable = 
    {
    2,
    inout_table
    };

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/*  2 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  4 */	NdrFcShort( 0x0 ),	/* Type Offset=0 */
/*  6 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  8 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */
/* 10 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 12 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  2 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/*  4 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  6 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */

			0x0
        }
    };
