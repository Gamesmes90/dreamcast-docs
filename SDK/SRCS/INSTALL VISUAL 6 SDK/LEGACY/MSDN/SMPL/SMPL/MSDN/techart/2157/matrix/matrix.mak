# Microsoft Visual C++ generated build script - Do not modify

PROJ = MATRIX
DEBUG = 1
PROGTYPE = 1
CALLER = 
ARGS = 
DLLS = 
ORIGIN = MSVCNT
ORIGIN_VER = 1.00
PROJPATH = D:\MSTOOLS\SAMPLES\DEADLOCK\MATRIX\INNOCENT\ 
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = 
FIRSTCPP = 
RC = rc
CFLAGS_D_WDLL32 = /nologo /D_X86_ /W3 /FR /YX /D_DEBUG /Zi /MT /Fd"MATRIX.PDB" /Fp"MATRIX.PCH"
CFLAGS_R_WDLL32 = /nologo /D_X86_ /W3 /FR /YX /O2 /DNDEBUG /MT /Fp"MATRIX.PCH"
LFLAGS_D_WDLL32 = /NOLOGO /DEBUG /DEBUGTYPE:cv /SUBSYSTEM:windows user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib olecli32.lib olesvr32.lib shell32.lib
LFLAGS_R_WDLL32 = /NOLOGO /SUBSYSTEM:windows user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib olecli32.lib olesvr32.lib shell32.lib
LFLAGS_D_LIB32 = /NOLOGO
LFLAGS_R_LIB32 = /NOLOGO
LIBS_D_WDLL32 = 
LIBS_R_WDLL32 = 
RCFLAGS32 = 
D_RCDEFINES32 = -d_DEBUG
R_RCDEFINES32 = -dNDEBUG
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WDLL32)
LFLAGS = $(LFLAGS_D_WDLL32)
LIBS = $(LIBS_D_WDLL32)
LFLAGS_LIB=$(LFLAGS_D_LIB32)
MAPFILE_OPTION = 
RCDEFINES = $(D_RCDEFINES32)
!else
CFLAGS = $(CFLAGS_R_WDLL32)
LFLAGS = $(LFLAGS_R_WDLL32)
LIBS = $(LIBS_R_WDLL32)
MAPFILE_OPTION = 
LFLAGS_LIB=$(LFLAGS_R_LIB32)
RCDEFINES = $(R_RCDEFINES32)
!endif
SBRS = MATRIX.SBR


MATRIX_DEP =  \
	d:\mstools\samples\deadlock\matrix\innocent\matrix.hpp


all:	$(PROJ).DLL $(PROJ).BSC

MATRIX.OBJ:	MATRIX.CPP $(MATRIX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MATRIX.CPP


$(PROJ).DLL:	MATRIX.OBJ $(OBJS_EXT) $(LIBS_EXT)
	echo >NUL @<<$(PROJ).CRF
MATRIX.OBJ 
$(OBJS_EXT)
-DLL -OUT:$(PROJ).DLL
$(MAPFILE_OPTION)

$(LIBS)
$(LIBS_EXT)
$(DEFFILE_OPTION) -implib:$(PROJ).lib
<<
	link $(LFLAGS) @$(PROJ).CRF

run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
