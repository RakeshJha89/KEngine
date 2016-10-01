/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#include <stdlib.h>
#include <memory.h>
#include "KTypes.h"

namespace Karma
{
	enum EMemoryAligment
	{
		ALIGN_DEFAULT = 0,
		ALIGN_MIN = 8
	};

	struct KMemory
	{
		static void* DefaultMalloc(size_t size)
		{
			return ::malloc(size);
		}

		static void DefaultFree(void* ptr)
		{
			::free(ptr);
		}

		static void* Memcopy(void* pDst, const void* pSrc, size_t count)
		{
			return ::memcpy(pDst, pSrc, count);
		}

		static void* Memset(void* pDst, uint8 charVal, size_t count)
		{
			return ::memset(pDst, charVal, count);
		}

		static void* Malloc(size_t count, uint32 alignment = ALIGN_DEFAULT);
		static void* Realloc(void* pSrc, size_t count, uint32 alignment = ALIGN_DEFAULT);
		static void Free(void* pSrc);

	};
}