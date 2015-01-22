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
	${OBJECTDIR}/absensi/absensi_notebook.o \
	${OBJECTDIR}/absensi/absensi_panel.o \
	${OBJECTDIR}/absensi/izin_panel.o \
	${OBJECTDIR}/kepank/kelas_input_dialog.o \
	${OBJECTDIR}/kepank/kelas_panel.o \
	${OBJECTDIR}/kepank/kepank_notebook.o \
	${OBJECTDIR}/kepank/pangkat_input_dialog.o \
	${OBJECTDIR}/kepank/pangkat_panel.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/pegawai/pegawai_notebook.o \
	${OBJECTDIR}/pegawai/pegawai_panel.o \
	${OBJECTDIR}/pegawai/pegawai_salin_dialog.o


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

${OBJECTDIR}/absensi/absensi_notebook.o: absensi/absensi_notebook.cpp 
	${MKDIR} -p ${OBJECTDIR}/absensi
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/absensi/absensi_notebook.o absensi/absensi_notebook.cpp

${OBJECTDIR}/absensi/absensi_panel.o: absensi/absensi_panel.cpp 
	${MKDIR} -p ${OBJECTDIR}/absensi
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/absensi/absensi_panel.o absensi/absensi_panel.cpp

${OBJECTDIR}/absensi/izin_panel.o: absensi/izin_panel.cpp 
	${MKDIR} -p ${OBJECTDIR}/absensi
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/absensi/izin_panel.o absensi/izin_panel.cpp

${OBJECTDIR}/kepank/kelas_input_dialog.o: kepank/kelas_input_dialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/kepank
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kepank/kelas_input_dialog.o kepank/kelas_input_dialog.cpp

${OBJECTDIR}/kepank/kelas_panel.o: kepank/kelas_panel.cpp 
	${MKDIR} -p ${OBJECTDIR}/kepank
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kepank/kelas_panel.o kepank/kelas_panel.cpp

${OBJECTDIR}/kepank/kepank_notebook.o: kepank/kepank_notebook.cpp 
	${MKDIR} -p ${OBJECTDIR}/kepank
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kepank/kepank_notebook.o kepank/kepank_notebook.cpp

${OBJECTDIR}/kepank/pangkat_input_dialog.o: kepank/pangkat_input_dialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/kepank
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kepank/pangkat_input_dialog.o kepank/pangkat_input_dialog.cpp

${OBJECTDIR}/kepank/pangkat_panel.o: kepank/pangkat_panel.cpp 
	${MKDIR} -p ${OBJECTDIR}/kepank
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kepank/pangkat_panel.o kepank/pangkat_panel.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/pegawai/pegawai_notebook.o: pegawai/pegawai_notebook.cpp 
	${MKDIR} -p ${OBJECTDIR}/pegawai
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pegawai/pegawai_notebook.o pegawai/pegawai_notebook.cpp

${OBJECTDIR}/pegawai/pegawai_panel.o: pegawai/pegawai_panel.cpp 
	${MKDIR} -p ${OBJECTDIR}/pegawai
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pegawai/pegawai_panel.o pegawai/pegawai_panel.cpp

${OBJECTDIR}/pegawai/pegawai_salin_dialog.o: pegawai/pegawai_salin_dialog.cpp 
	${MKDIR} -p ${OBJECTDIR}/pegawai
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_UNICODE -D__WXMSW__ -I/D/wxWidgets-3.0.2/include -I../../../wxWidgets-3.0.2/lib/gcc_lib/mswud -I/D/IDE/mysql-connector-c++-noinstall-1.1.5-win32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pegawai/pegawai_salin_dialog.o pegawai/pegawai_salin_dialog.cpp

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
