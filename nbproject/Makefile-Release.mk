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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
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
LDLIBSOPTIONS=-L\"C\:/Program\ Files/MySQL/MySQL\ Server\ 5.6/lib\" -L../../IDE/MySQL++/lib -L../../wxWidgets-3.0.2/lib/gcc_lib -lmysqlpp -lmysqlclient -lwxmsw30u -lwxmsw30u_gl -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxexpat -lwxregexu -lgdi32 -lcomctl32 -lole32 -luuid -loleaut32 -lcomdlg32 -lwinspool resource.o

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas ${OBJECTFILES} ${LDLIBSOPTIONS} -s

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -s -DMYSQLPP_NO_DLL -D_UNICODE -D__WXMSW__ -I/C/Program\ Files/MySQL/MySQL\ Server\ 5.6/include -I../../IDE/MySQL++/include -I/D/wxWidgets-3.0.2/include -I../../wxWidgets-3.0.2/lib/gcc_lib/mswu -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsitkas.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
