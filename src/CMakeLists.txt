#Project file generator for KEngine
#Created/Maintained by Rakesh Jha.
#All rights reserved(2016)

SUBDIRS ( 	
			kAdapters 
			kCOre
			kEngine 
		)

SET	(	APPFRAMEWORK_HEADERS
		kAppFramework.h
		kAppFramework_Windows.h
	)

SET	(	APPFRAMEWORK_SOURCE
		kAppFramework_Windows.cpp
		AppEntry_Win32.cpp
	)