#Project file generator for KEngine
#Created/Maintained by Rakesh Jha.
#All rights reserved(2016)

SET	(	ADAPTER_HEADERS
		GraphicsAdapter.h
		GraphicsAdapter_OpenGL.h
		TimerAdapter.h
		TimerAdapter_Windows.h
	)

SET	(	ADAPTER_SOURCE
		GraphicsAdapter_OpenGL.cpp
		TimerAdapter_Windows.cpp
	)
	
ADD_LIBRARY	( kAdapters ${ADAPTER_HEADERS} ${ADAPTER_SOURCE} )
