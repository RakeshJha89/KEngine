#Project file generator for KEngine
#Created/Maintained by Rakesh Jha.
#All rights reserved(2016)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)

#disable incremental linking
SET(MSVC_INCREMENTAL_DEFAULT ON)

PROJECT( KEngine )
SET(KEngine_Version 1.1)

OPTION(BUILD_SHARED_LIBS "Use shared libraries" OFF)
OPTION(USE_MSVC_INCREMENTAL_LINKING "Use MSVC Incremental Linking" OFF)
OPTION(USE_MSVC_RUNTIME_LIBRARY_DLL "Use MSVC Runtime Library DLL (/MD or /MDd)" OFF)

IF(MSVC)
	IF (NOT USE_MSVC_INCREMENTAL_LINKING)
		SET( MSVC_INCREMENTAL_YES_FLAG "/INCREMENTAL:NO")

		STRING(REPLACE "INCREMENTAL:YES" "INCREMENTAL:NO" replacementFlags ${CMAKE_EXE_LINKER_FLAGS_DEBUG})
		SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "/INCREMENTAL:NO ${replacementFlags}" )
		MESSAGE("CMAKE_EXE_LINKER_FLAGS_DEBUG=${CMAKE_EXE_LINKER_FLAGS_DEBUG}")

		STRING(REPLACE "INCREMENTAL:YES" "INCREMENTAL:NO" replacementFlags2 ${CMAKE_EXE_LINKER_FLAGS})

		SET(CMAKE_EXE_LINKER_FLAGS ${replacementFlag2})
		STRING(REPLACE "INCREMENTAL:YES" "" replacementFlags3 "${CMAKE_EXTRA_LINK_FLAGS}")

		SET(CMAKE_EXTRA_LINK_FLAGS ${replacementFlag3})


		STRING(REPLACE "INCREMENTAL:YES" "INCREMENTAL:NO" replacementFlags3 "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO}")
		SET(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO ${replacementFlags3})
		SET(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/INCREMENTAL:NO ${replacementFlags3}" )

	ENDIF (NOT USE_MSVC_INCREMENTAL_LINKING)

	IF (NOT USE_MSVC_RUNTIME_LIBRARY_DLL)
		#We statically link to reduce dependancies
		FOREACH(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO )
			IF(${flag_var} MATCHES "/MD")
				STRING(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
			ENDIF(${flag_var} MATCHES "/MD")
			IF(${flag_var} MATCHES "/MDd")
				STRING(REGEX REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
			ENDIF(${flag_var} MATCHES "/MDd")
		ENDFOREACH(flag_var)
	ENDIF (NOT USE_MSVC_RUNTIME_LIBRARY_DLL)

	OPTION(USE_MSVC_FAST_FLOATINGPOINT "Use MSVC /fp:fast option"	ON)
	OPTION(USE_MSVC_SSE "Use MSVC /arch:sse option"	ON)
	IF (USE_MSVC_FAST_FLOATINGPOINT)
		  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:fast")
	ENDIF()
	IF (USE_MSVC_SSE)
	  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE")
	ENDIF()
ENDIF(MSVC)

IF (WIN32)
OPTION(INTERNAL_CREATE_DISTRIBUTABLE_MSVC_PROJECTFILES "Create MSVC projectfiles that can be distributed" OFF)

IF (INTERNAL_CREATE_DISTRIBUTABLE_MSVC_PROJECTFILES)
	SET (LIBRARY_OUTPUT_PATH ${KEngine_SOURCE_DIR}/lib CACHE PATH "Single output directory for building all libraries.")
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${KEngine_SOURCE_DIR})
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${KEngine_SOURCE_DIR})
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${KEngine_SOURCE_DIR})
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${KEngine_SOURCE_DIR})
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${KEngine_SOURCE_DIR})
ELSE()
	SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE PATH "Single output directory for building all libraries.")
ENDIF()


OPTION(INTERNAL_CREATE_MSVC_RELATIVE_PATH_PROJECTFILES "Create MSVC projectfiles with relative paths" OFF)
OPTION(INTERNAL_ADD_POSTFIX_EXECUTABLE_NAMES "Add MSVC postfix for executable names (_Debug)" OFF)

SET(CMAKE_DEBUG_POSTFIX "_Debug" CACHE STRING "Adds a postfix for debug-built libraries.")
SET(CMAKE_MINSIZEREL_POSTFIX "_MinsizeRel" CACHE STRING "Adds a postfix for MinsizeRelease-built libraries.")
SET(CMAKE_RELWITHDEBINFO_POSTFIX "_RelWithDebugInfo" CACHE STRING "Adds a postfix for ReleaseWithDebug-built libraries.")


IF (INTERNAL_CREATE_MSVC_RELATIVE_PATH_PROJECTFILES)
SET(CMAKE_SUPPRESS_REGENERATION  1)
SET(CMAKE_USE_RELATIVE_PATHS 1)
ENDIF(INTERNAL_CREATE_MSVC_RELATIVE_PATH_PROJECTFILES)

ENDIF (WIN32)

IF (WIN32)
OPTION(USE_GLUT "Use Glut"	ON)
ADD_DEFINITIONS( -D_CRT_SECURE_NO_WARNINGS )
ADD_DEFINITIONS( -D_CRT_SECURE_NO_DEPRECATE )
ADD_DEFINITIONS( -D_SCL_SECURE_NO_WARNINGS )

IF (USE_GLUT AND MSVC)
	string (REPLACE "/D_WINDOWS" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
	remove_definitions(-D_WINDOWS )
ENDIF()

ELSE(WIN32)
OPTION(USE_GLUT "Use Glut"	ON)
ENDIF(WIN32)

FIND_PACKAGE(OpenGL)
IF (OPENGL_FOUND)
	MESSAGE("OPENGL FOUND")
	MESSAGE(${OPENGL_LIBRARIES})
ELSE (OPENGL_FOUND)
	MESSAGE("OPENGL NOT FOUND")
	SET(OPENGL_gl_LIBRARY opengl32)
	SET(OPENGL_glu_LIBRARY glu32)
ENDIF (OPENGL_FOUND)

IF(EXISTS ${KEngine_SOURCE_DIR}/src AND IS_DIRECTORY ${KEngine_SOURCE_DIR}/src)
		SUBDIRS(src)
ENDIF()


