project "KCore"
    print("Building KCore...")
    kind "StaticLib"    
	language "C++"
	architecture "x86"
	systemversion "10.0.10586.0"
	characterset "MBCS"
    pchheader "precompiled_Core.h"
    pchsource "precompiled_Core.cpp"
    files
    { 
        "**.h",
        "**.cpp"
    }

    location  "../../build" -- Project Generated Directory.
    targetdir "$(ProjectDir)bin/$(Configuration)/"
    objdir ("$(ProjectDir)bin/$(Configuration)/obj")

    --Configuration Debug
    print("Building Debug")
 	filter "configurations:Debug"
		sysincludedirs { "" }
		includedirs { "" }
	    libdirs { "" }
		excludes { "" }      
		links { "" }
        flags { "StaticRuntime", "Symbols" }		
		defines { "DEBUG", "WIN_32", "WIN32", "_DEBUG", "_WINDOWS", "KARMA_GL" }

    --Configuration Release
	print("Building Release")
	filter "configurations:Release"
        sysincludedirs { "" }
		includedirs { "" }
	    libdirs { "" }
		excludes { "" }      
		links { "" }
        flags { "StaticRuntime", "Optimize" }  		
		defines { "NDEBUG", "WIN_32", "WIN32", "_WINDOWS", "KARMA_GL" }		

print("Project Generation done...")