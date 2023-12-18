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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/rutas_aereas/src/almacenRutas.o \
	${OBJECTDIR}/rutas_aereas/src/pais.o \
	${OBJECTDIR}/rutas_aereas/src/paises.o \
	${OBJECTDIR}/rutas_aereas/src/punto.o \
	${OBJECTDIR}/rutas_aereas/src/rutas.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafinaled

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafinaled: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafinaled ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/rutas_aereas/src/almacenRutas.o: rutas_aereas/src/almacenRutas.cpp
	${MKDIR} -p ${OBJECTDIR}/rutas_aereas/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rutas_aereas/src/almacenRutas.o rutas_aereas/src/almacenRutas.cpp

${OBJECTDIR}/rutas_aereas/src/pais.o: rutas_aereas/src/pais.cpp
	${MKDIR} -p ${OBJECTDIR}/rutas_aereas/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rutas_aereas/src/pais.o rutas_aereas/src/pais.cpp

${OBJECTDIR}/rutas_aereas/src/paises.o: rutas_aereas/src/paises.cpp
	${MKDIR} -p ${OBJECTDIR}/rutas_aereas/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rutas_aereas/src/paises.o rutas_aereas/src/paises.cpp

${OBJECTDIR}/rutas_aereas/src/punto.o: rutas_aereas/src/punto.cpp
	${MKDIR} -p ${OBJECTDIR}/rutas_aereas/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rutas_aereas/src/punto.o rutas_aereas/src/punto.cpp

${OBJECTDIR}/rutas_aereas/src/rutas.o: rutas_aereas/src/rutas.cpp
	${MKDIR} -p ${OBJECTDIR}/rutas_aereas/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/rutas_aereas/src/rutas.o rutas_aereas/src/rutas.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
