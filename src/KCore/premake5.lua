project "KCore"
    print("Building KCore...")
    kind "StaticLib"    
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
		--sysincludedirs {"$(ProjectDir);$(ProjectDir)KCore;" }    
--[[
		includedirs { "$(ProjectDir)", "$(ProjectDir)Libs", "$(ProjectDir)Libs/KCore/include/" }
	    libdirs { "$(ProjectDir)Libs", "$(ProjectDir)Libs/KCore/$(Configuration)/" }
]]--
		excludes { "" }      
		links { "" }
        flags { "StaticRuntime", "Symbols" }		
		defines { "DEBUG", "WIN_32", "WIN32", "_DEBUG", "_WINDOWS" }

    --Configuration Release
	print("Building Release")
	filter "configurations:Release"
		--sysincludedirs {"$(ProjectDir);$(ProjectDir)KCore;" }
--[[		
		includedirs { "$(ProjectDir)", "$(ProjectDir)Libs", "$(ProjectDir)Libs/KCore/include/" }
	    libdirs { "$(ProjectDir)Libs", "$(ProjectDir)Libs/KCore/$(Configuration)/" }
]]--
		excludes { "" }		        
		links { "" }
        flags { "StaticRuntime", "Optimize" }  		
		defines { "NDEBUG", "WIN_32", "WIN32", "_WINDOWS" }		

print("Project Generation done...")