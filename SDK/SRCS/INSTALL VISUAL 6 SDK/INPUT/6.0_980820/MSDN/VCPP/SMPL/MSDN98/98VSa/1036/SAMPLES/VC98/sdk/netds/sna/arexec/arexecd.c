/*****************************************************************************
 *
 *  MODULE NAME : AREXECD.C
 *
 *  COPYRIGHTS:
 *             This module contains code made available by IBM
 *             Corporation on an AS IS basis.  Any one receiving the
 *             module is considered to be licensed under IBM copyrights
 *             to use the IBM-provided source code in any way he or she
 *             deems fit, including copying it, compiling it, modifying
 *             it, and redistributing it, with or without
 *             modifications.  No license under any IBM patents or
 *             patent applications is to be implied from this copyright
 *             license.
 *
 *             A user of the module should understand that IBM cannot
 *             provide technical support for the module and will not be
 *             responsible for any consequences of use of the program.
 *
 *             Any notices, including this one, are not to be removed
 *             from the module without the prior written consent of
 *             IBM.
 *
 *  AUTHOR:    Peter J. Schwaller
 *             VNET:     PJS at RALVM6           Tie Line: 444-4376
 *             Internet: pjs@ralvm6.vnet.ibm.com     (919) 254-4376
 *
 *  FUNCTION:  This module is the server side of AREXEC.  This module
 *             will execute a specified command and route the output
 *             back to the AREXEC transaction program.
 *
 *  AVAILABILITY:
 *             These sample programs and source are also available on
 *             CompuServe through the APPC Information Exchange.  To get
 *             to the APPC forum just type 'GO APPC' from any CompuServe
 *             prompt.  The samples are available in the Sample Programs
 *             library section.  Just search on the keyword CPICPGMS to
 *             find all the samples in this series.
 *
 *             Updates for the sample programs and support for many more
 *             CPI-C platforms will also be made available on CompuServe.
 *
 *  RELATED FILES:
 *             See AREXEC.DOC for usage instructions.
 *
 *  CHANGE HISTORY:
 *  Date       Description
 *  06/15/92   NS/DOS accepts version 2.02 into system test.
 *  08/05/92   Version 2.31 released to CompuServe
 *             This version was also distributed at the APPC/APPN Platform
 *             Developer's Conference held in Raleigh, NC.
 *  08/13/92   Changed all printf and fprintf calls to use a write_*() call.
 *  08/24/92   Version 2.32 released to CompuServe.
 *  09/22/92   Version 2.33 released to CompuServe.
 *  11/17/92   Supports sending operating system string - see CPICERR.C
 *             Version 2.34 released to CompuServe
 *  01/07/93   Version 2.35
 *             Fixed a number of problems when compiling with IBM C Set/2
 *                password input was displayed
 *                timer resolution was 1 second
 *                arexecd server did not function properly
 *
 *****************************************************************************/

#ifdef WIN32                                                           /*WIN32*/
#include <windows.h>                                                   /*WIN32*/
SERVICE_STATUS_HANDLE stat_hand;                                       /*WIN32*/
SERVICE_STATUS servstat;                                               /*WIN32*/
#endif                                                                 /*WIN32*/

#include "wincpic.h"

/* standard C include files */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Set up constant declarations */
#include "cpicdefs.h"

/* Collection of routines with special ported version for each platform */
#include "cpicport.h"

#define  MAX_COMMAND_LENGTH   500

/*--------------------------------------------------------------------------*/
/*      CPI-C Error Handling Global Variables                               */
/*--------------------------------------------------------------------------*/
#include "cpicerrs.h"                        /* CPI-C error handling vars.   */
CPICERR * cpicerr;

/* Define these here so we can make changes throughout the code. */
/*
 * The PROGRAM_INFO string should be kept in sync with the
 * MAJOR_VERSION and MINOR_VERSION constants.  Although the
 * cpicerr_exchange_version() call will support values up to 255,
 * values for MINOR_VERSION should be from 00-99 to maintain the
 * two character format in the version string.
 */
#define  PROGRAM_NAME      "AREXECD"
#define  PROGRAM_INFO      "version 2.35"
#define  MAJOR_VERSION     (2)
#define  MINOR_VERSION     (35)
#define  LOG_FILE_NAME     "arexecd.err"
#define  LOG_FILE_PATH     "$LOGPATH"


char * intro[] = {
    PROGRAM_NAME " " PROGRAM_INFO " - Remote execution of a command. (Server)",
    NULL
    };


void
TPStart(void)
{
    /* Variables used for CPI-C calls */
    unsigned char cm_conv_id[8];            /* CPI-C conversation ID         */
    CM_INT32    temp;                                                 /*WIN32*/
    CM_INT32    cm_rc;                      /* CPI-C return code             */
    CM_INT32    length;                     /* generic length variable       */
    CM_INT32    rts_received;               /* request to send received      */
    CM_INT32    max_receive_len;            /* Max receive length on CMRCV   */
    CM_INT32    what_received;              /* What received parm from CMRCV */
    CM_INT32    received_len;               /* Amount of data rcvd on CMRCV  */
    CM_INT32    status_received;            /* Status from CMRCV             */

    /* Data buffer for send and receive */
    char        buffer[MAX_COMMAND_LENGTH]; /* CPIC data buffer              */

    char partner_major_version;
    char partner_minor_version;

    unsigned char destination[MAX_FQPLU_NAME];

    show_info(intro);

#ifdef WIN32
    {
       /**********************************************************************/
       /* Initialisation for WinCPIC                                         */
       /**********************************************************************/
       unsigned short WinCPICVERSION = 0x0001;
       WCPICDATA CPICData;
       if (WinCPICStartup(WinCPICVERSION,&CPICData))
       {
         return;
       }
       /**********************************************************************/
       /* Set our local TP Name                                              */
       /**********************************************************************/
       temp=7;
       cmsltp("AREXECD",&temp,&cm_rc);
    }
#endif

    /*
     * Initialize the CPICERR structure.  This is done before the CMINIT
     * call so that we can use CPICERR for help with errors on CMINIT.
     * The procedure is in CPICERR.C
     */
    cpicerr = cpicerr_new();
    cpicerr_set_program_name(cpicerr, PROGRAM_NAME);
    cpicerr_set_program_info(cpicerr, PROGRAM_INFO);
    cpicerr_set_major_version(cpicerr, MAJOR_VERSION);
    cpicerr_set_minor_version(cpicerr, MINOR_VERSION);
    cpicerr_set_log_file_name(cpicerr, LOG_FILE_NAME);
    cpicerr_set_log_file_path(cpicerr, LOG_FILE_PATH);

    cmaccp(cm_conv_id,
           &cm_rc);
    /*
     * Note that as we have used cmsltp to specify our local TP name,
     * cmaccp may return asynchronously, so we must do a cmwait
     */
    if (cm_rc == CM_OPERATION_INCOMPLETE)                             /*WIN32*/
    {                                                                 /*WIN32*/
      cmwait(cm_conv_id, &cm_rc, &temp);                              /*WIN32*/
    }                                                                 /*WIN32*/

   /*------------------------------------------------------------------------*
    * Fill in conversation information for CPI-C error reporting.
    *------------------------------------------------------------------------*/
    cpicerr_set_conv_id(cpicerr, cm_conv_id);

    if (cm_rc != CM_OK) {
        cpicerr_handle_rc(cpicerr, MSG_CMACCP, cm_rc);
    } else {
        length = 17;
        cmepln(cm_conv_id,
               destination,
               &length,
               &cm_rc );
        destination[(unsigned int)length] = '\0';
        write_output("\nContacted by partner: ");
        write_output("%s", destination);
        write_output("\n");
    }

    cpicerr_exchange_version(cpicerr,
                             cm_conv_id,
                             CM_RECEIVE_STATE,
                             &partner_major_version,
                             &partner_minor_version);

    {
    CM_SEND_TYPE send_type = CM_SEND_AND_FLUSH;
    cmsst(cm_conv_id,                       /* Set send type                 */
          &send_type,
          &cm_rc);
    }

    max_receive_len = MAX_COMMAND_LENGTH-1;

    cmrcv(cm_conv_id,                       /* Receive Data                  */
          (unsigned char *) buffer,         /* Data Pointer                  */
          &max_receive_len,                 /* Size of Data Buffer           */
          &what_received,                   /* returned - what received      */
          &received_len,                    /* returned - length of data     */
          &status_received,                 /* returned - status received    */
          &rts_received,                    /* returned - request to send    */
          &cm_rc);

    if (cm_rc != CM_OK) cpicerr_handle_rc(cpicerr, MSG_CMRCV, cm_rc);

    buffer[(unsigned int)received_len] = '\0';

    convert_from_ascii(buffer, strlen(buffer));

    write_output("The command is:\n%s\n\n", buffer);

    execute_and_send_output(buffer,
                            cm_conv_id,
                            cpicerr);

    {
    CM_DEALLOCATE_TYPE deallocate_type = CM_DEALLOCATE_FLUSH;

    cmsdt(cm_conv_id,
          &deallocate_type,
          &cm_rc);
    }

    cmdeal(cm_conv_id,
           &cm_rc);
    if (cm_rc) cpicerr_handle_rc(cpicerr, MSG_CMDEAL, cm_rc);

    /* destroy the object we created with cpicerr_new() */
    cpicerr_destroy(cpicerr);

    exit(EXIT_SUCCESS);

}

#ifdef WIN32
/*****************************************************************************/
/* The following code makes this TP invokable as an NT service. There are 3  */
/* routines.                                                                 */
/*                                                                           */
/* 1. main. This is the entry point for the process, it sets up a service    */
/*          table entry and then calls StartServiceCtrlDispatcher. This call */
/*          doesn't return, but uses the thread which called it as a         */
/*          control dispatcher for all the services implemented by this      */
/*          process (in this case, just the TP itself).                      */
/*                                                                           */
/* 2. ServiceMain. This is the main entry point for the service itself, the  */
/*          service control dispatcher creates a thread to start at this     */
/*          routine. It must register a service control handler for the      */
/*          service which will be called by the control dispatcher when it   */
/*          has control instructions for the service. It then informs the    */
/*          service control manager that the service is running and finally  */
/*          calls the start of the TP itself. This routine should not return */
/*          until the service is ready to die.                               */
/*                                                                           */
/* 3. ControlHandler. This routine is called by the control dispatcher when  */
/*          it has instructions for the service. We do not respond to any    */
/*          of the instructions as this service should be transitory and not */
/*          actually run for more than a few seconds so we don't need to do  */
/*          anything with the STOP or SHUTDOWN requests.                     */
/*          Note that we MUST call SetServiceStatus, even if the status      */
/*          hasn't changed.                                                  */
/*****************************************************************************/

void __cdecl main( DWORD argc, LPSTR * argv);
void WINAPI ServiceMain(DWORD dwNumServiceArgs, LPTSTR * lpServiceArgs);
VOID WINAPI ControlHandler(DWORD dwControl);
SERVICE_STATUS_HANDLE stat_hand;
SERVICE_STATUS servstat;

void __cdecl main( DWORD argc, LPSTR * argv)
{
  SERVICE_TABLE_ENTRY  stab[2];

  /***************************************************************************/
  /* Start the control dispatcher. This call gives the SCManager this        */
  /* thread for the entire period that this service is running, so that it   */
  /* can call us back with service controls. It will spawn a new thread to   */
  /* run the service itself, starting at entrypoint ServiceMain.             */
  /***************************************************************************/
  stab[0].lpServiceName = "AREXECD\0";
  stab[0].lpServiceProc = ServiceMain;

  stab[1].lpServiceName = NULL;
  stab[1].lpServiceProc = NULL;

  StartServiceCtrlDispatcher(stab);

}


/*****************************************************************************/
/* This routine is the entry-point for the service itself the service        */
/* control dispatcher creates a thread to start here when we issue           */
/* StartServiceControlDispatcher.                                            */
/*                                                                           */
/* Inputs:  number of arguments to services, array of strings.               */
/*                                                                           */
/* Outputs: none                                                             */
/*                                                                           */
/*****************************************************************************/
void WINAPI ServiceMain(DWORD dwNumServiceArgs, LPTSTR * lpServiceArgs)
{

  DWORD rc;

  stat_hand = RegisterServiceCtrlHandler("AREXECD\0", ControlHandler);
  if (stat_hand == (SERVICE_STATUS_HANDLE)NULL)
  {
    rc = GetLastError();
    DebugBreak();
  }

  /***************************************************************************/
  /* Let the SCManager know that we are running.                             */
  /***************************************************************************/
  servstat.dwServiceType              = SERVICE_WIN32;
  servstat.dwCurrentState             = SERVICE_RUNNING;
  servstat.dwControlsAccepted         = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
  servstat.dwWin32ExitCode            = NO_ERROR;
  servstat.dwServiceSpecificExitCode  = NO_ERROR;
  servstat.dwCheckPoint               = 0;
  servstat.dwWaitHint                 = 0;

  rc = SetServiceStatus(stat_hand, &servstat);
  if (!rc)
  {
     rc = GetLastError();
     DebugBreak();
  }

  TPStart();

}

/*****************************************************************************/
/* This routine is the callback from the SCManager to handle specific        */
/* service control requests. It MUST call SetServiceStatus before it         */
/* returns, regardless of whether the status has changed.                    */
/*                                                                           */
/* Inputs: service control requested                                         */
/*                                                                           */
/* Outputs: none                                                             */
/*                                                                           */
/*****************************************************************************/
VOID WINAPI ControlHandler(DWORD dwControl)
{
  DWORD rc;

  switch (dwControl)
  {
    case SERVICE_CONTROL_STOP :
      servstat.dwCurrentState = SERVICE_STOP_PENDING;
      servstat.dwWaitHint     = 24000;
      break;

    case SERVICE_CONTROL_PAUSE :
    case SERVICE_CONTROL_CONTINUE :
    case SERVICE_CONTROL_INTERROGATE :
      servstat.dwWaitHint     = 0;
      break;

	 case SERVICE_CONTROL_SHUTDOWN:
      servstat.dwCurrentState = SERVICE_STOP_PENDING;
      servstat.dwWaitHint     = 10000;
		break;
  }

  rc=SetServiceStatus(stat_hand, &servstat);
  if (!rc)
  {
     rc=GetLastError();
  }

}

#endif

