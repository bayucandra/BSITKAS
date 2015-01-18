#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/kepank/kelas_input_dialog.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../wxWidgets-3.0.2/lib/gcc_lib -L/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/lib -lwxmsw30u_adv -lwxmsw30u_core -lwxbase30u -lwxbase30u_xml -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxexpat -lwxregexu -lgdi32 -lcomctl32 -lole32 -luuid -loleaut32 -lcomdlg32 -lwinspool -lwxmsw30u_xrc resource.o -lmysqlcppconn-static -lmysql

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas ${OBJECTFILES} ${LDLIBSOPTIONS}

: /D/Projects/Windows/BSITKAS/resource.rc 
	@echo Building resource.o
	windres.exe resource.rc resource.o

${OBJECTDIR}/kepank/kelas_input_dialog.o: kepank/kelas_input_dialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/kepank
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kepank/kelas_input_dialog.o kepank/kelas_input_dialog.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas.exe
	${RM} 

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
