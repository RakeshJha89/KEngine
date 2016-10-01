/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#include <iostream>
#include <sstream>
#include <assert.h>

#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
//OpenGl specific.
#if defined KARMA_GL
    #define KARMA_USE_GL 1
    #define KARMA_USE_DX 0
#endif

//DirectX specific.
#if defined KARMA_DX
    #define KARMA_USE_GL 0
    #define KARMA_USE_DX 1
#endif

#if defined (_DEBUG)
#define DEBUGOUT( s )           \
{                               \
   std::wostringstream os_;     \
   os_ << s;                    \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define LOG_MSG( s )    \
{                       \
    printf("%s", s);    \
}

#define ASSERT_CHECK(cond)      \
do                              \
{                               \
    assert(cond);               \
}                               \
while(0);

#else

#define DEBUGOUT( s )
#define LOG_MSG( s )

#endif

    


//Constants.
#define WIDTH 1024
#define HEIGHT 768

#define ONEOVERSIX 0.1666f
#define MIN_FLOAT_THRESHOLD 0.0001f

#ifndef FORCEINLINE
#define FORCEINLINE inline
#endif
//Windows
#include <stdio.h>
#include <windows.h>