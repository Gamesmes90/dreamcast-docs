@echo off
REM **************************************************************************
REM * BUILDBOR.BAT                    Copyright (C) 1995 Microsoft Corp.     *
REM *                                                                        *
REM * This command file allows you to build the sample C programs using the  *
REM * Borland DOS compiler.                                                  *
REM **************************************************************************

if "%1" == "?" goto Usage
if "%1" == "" goto Usage

set MODEL_TYPE=
if "%2" == "medium" set MODEL_TYPE=%2
if "%2" == "large" set MODEL_TYPE=%2
if "%MODEL_TYPE%" == "" set MODEL_TYPE=large

set DEBUG_TYPE=
if "%3" == "debug" set DEBUG_TYPE=%3
if "%3" == "normal" set DEBUG_TYPE=%3
if "%DEBUG_TYPE%" == "" set DEBUG_TYPE=normal

@echo *** You may have to modify the -I (include path) and -L (library path) 
@echo *** in the BUILDBOR.MAK files...
@echo.

@echo *** Application Name: %1
@echo *** Memory Model    : %MODEL_TYPE%
@echo *** Compile Type    : %DEBUG_TYPE%
@echo.

make -B -f buildbor.mak APP=%1 MODEL_TYPE=%MODEL_TYPE% DEBUG_TYPE=%DEBUG_TYPE%
goto Done


:Usage
@echo Syntax: BUILDBOR filename {medium or large} {debug or normal}
@echo.
@echo filename  The name of the source file to build (do not type the .c extension).
@echo.
@echo medium    Medium model application.
@echo large     Large model application.
@echo.
@echo debug     Adds debug information to the application.
@echo normal    The application is optimized and contains no debug information.

:Done
