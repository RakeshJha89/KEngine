project "KUnitTestGoogle"
print("Building KUnitTestGoogle...")
	kind "ConsoleApp"
	language "C++"
	architecture "x86"	    
	systemversion "10.0.10586.0"
	characterset "MBCS"	
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
		includedirs { "$(ProjectDir)../src/KFrameworkAI/", "$(ProjectDir)../thirdparty/gtest/include/", "$(ProjectDir)../thirdparty/gmock/include/" }
        libdirs { "$(ProjectDir)bin/$(Configuration)/", "$(ProjectDir)../thirdparty/gtest/$(Configuration)/", "$(ProjectDir)../thirdparty/gmock/$(Configuration)/" }
		excludes { "" }		
        entrypoint("")        
		links { "gtest" , "gmock", "KFrameworkAI" }
        flags { "StaticRuntime", "Symbols" }
        postbuildcommands { "$(TargetDir)$(TargetFileName)" }		
		defines { "DEBUG", "WIN_32", "WIN32", "_DEBUG", "_WINDOWS" }    
		
    --Configuration Release
	print("Building Release")
	filter "configurations:Release"
		sysincludedirs { "" }		
		includedirs { "$(ProjectDir)../src/KFrameworkAI/", "$(ProjectDir)../thirdparty/gtest/include/", "$(ProjectDir)../thirdparty/gmock/include/" }
	    libdirs { "$(ProjectDir)bin/$(Configuration)/", "$(ProjectDir)../thirdparty/gtest/$(Configuration)/", "$(ProjectDir)../thirdparty/gmock/$(Configuration)/" }
		excludes { "" }		
        entrypoint("")        
		links { "gtest" , "gmock", "KFrameworkAI" }    
        flags { "StaticRuntime", "Optimize" }
        postbuildcommands { "$(TargetDir)$(TargetFileName)" }		
		defines { "NDEBUG", "WIN_32", "WIN32", "_WINDOWS" }		
				
print("Project Generation done...")

