project "XCFrameworkAI"
print("Building C++ Win32 Project XCFrameworkAI")
	kind "StaticLib"
	language "C++"
	architecture "x86"
	targetdir "bin/%{cfg.buildcfg}"
	systemversion "10.0.10586.0"
	characterset "MBCS"
	
	files { "**.h", "**.cpp" }
    flags { "StaticRuntime" }
    
	vpaths
    {
        ["Header Files"] = "*.h",
        ["Header Files/AIBehavior"] = "AIBehavior/**.h",
        ["Header Files/AIBehaviorMocks"] = "AIBehaviorMocks/**.h",
        ["Header Files/AIBlackboardKeys"] = "AIBlackboardKeys/**.h",
        
        ["Source Files"] = "*.cpp",
        ["Source Files/AIBehavior"] = "AIBehavior/**.cpp",
        ["Source Files/AIBehaviorMocks"] = "AIBehaviorMocks/**.cpp",
        ["Source Files/AIBlackboardKeys"] = "AIBlackboardKeys/**.cpp"
    }

    sysincludedirs { XCFrameworkPath.."AIFramework" }
    includedirs { "" }
    libdirs { "" }
    
	--Configuration Debug
	print("Building Debug")
	filter "configurations:Debug"

		excludes { "**/Orbis/**", "**orbis.cpp", "**/Durango/**", "**durango.cpp", "**editor.cpp", "**/Editor/**", "**Editor.cpp", "**Editor**.*", "**/DDSTextureLoader_Legacy/**", "**.pssl", "**/XC_Shaders/src/**"}
        
		links { "" }
		
		defines { "DEBUG", "WIN_32", "WIN32", "_DEBUG", "_WINDOWS" }

		symbols "On"
		
		targetdir "$(ProjectDir)bin/$(Configuration)/"
		
	--Configuration Release
	print("Building Release")
	filter "configurations:Release"

		excludes { "**/Orbis/**", "**orbis.cpp", "**/Durango/**", "**durango.cpp", "**editor.cpp", "**/Editor/**", "**Editor.cpp", "**Editor**.*", "**/DDSTextureLoader_Legacy/**", "**.pssl", "**/XC_Shaders/src/**"}
		        
		links { "" }
    		
		defines { "NDEBUG", "WIN_32", "WIN32", "_WINDOWS" }
		
		symbols "On"
      	
		optimize "On"
		
		targetdir "$(ProjectDir)bin/$(Configuration)/"
				
print("Project Generation done...")