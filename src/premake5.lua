--[[
Created/Maintained by Rakesh Jha. All rights reserved.
Created on 13/09/2016
A single premake file to handle all subprojects
Promotes easy maintenance.
--]]
    -- Clean Function --
newaction {
   trigger     = "clean",
   description = "clean the software",
   onStart = function()
        print("Starting Cleaning..")
   end,
   execute     = function ()
      print("clean the build...")
      os.rmdir("../build")
      print("done.")
   end
}

newoption {
		trigger     = "targetdir",
		value       = "path such as ../bin",
		description = "Set the output location for the generated project files"
	}

--[[
function link_GL()
    libdirs "../thirdparty/libs/%{cfg.longname}/gl"
    
    configuration "Debug"
        links { "glew32sd", "glfw3" }
    configuration "Release"
        links { "glew32s", "glfw3" }
end
--]]

workspace "KarmaEngine"
    configurations { "Release", "Debug" }
    location "../build"

--App
--Win32
project "KarmaEngine"
    print("Building KarmaEngine...")
    kind "WindowedApp"    
	language "C++"
	architecture "x86"
	systemversion "10.0.10586.0"
	characterset "MBCS"   
    files 
    { 
        "*.h",
        "*.cpp"
    }

    location  "../build" -- Project Generated Directory.
    targetdir "$(ProjectDir)bin/$(Configuration)/"
    objdir ("$(ProjectDir)bin/$(Configuration)/obj")
    
    filter { "system:windows" }
		links	{ "OpenGL32" }
	
	filter { "system:not windows" }
		links { "GL" }

    --Configuration Debug
    print("Building Debug")
 	filter "configurations:Debug"
		--sysincludedirs {"$(ProjectDir);$(ProjectDir)KAdapter;" }    
--[[
		includedirs { "$(ProjectDir)", "$(ProjectDir)Libs", "$(ProjectDir)Libs/KAdapter/include/" }
	    libdirs { "$(ProjectDir)Libs", "$(ProjectDir)Libs/KAdapter/$(Configuration)/" }
]]--
		excludes { "" }        
		links { "OpenGL32" }
        flags { "StaticRuntime", "Symbols" }		
		defines { "DEBUG", "WIN_32", "WIN32", "_DEBUG", "_WINDOWS", "KARMA_GL" }

    --Configuration Release
	print("Building Release")
	filter "configurations:Release"
		--sysincludedirs {"$(ProjectDir);$(ProjectDir)KAdapter;" }
--[[		
		includedirs { "$(ProjectDir)", "$(ProjectDir)Libs", "$(ProjectDir)Libs/KAdapter/include/" }
	    libdirs { "$(ProjectDir)Libs", "$(ProjectDir)Libs/KAdapter/$(Configuration)/" }
]]--
		excludes { "" }		        
		links { "OpenGL32" }
        flags { "StaticRuntime", "Optimize" }    		
		defines { "NDEBUG", "WIN_32", "WIN32", "_WINDOWS", "KARMA_GL" }  


include("KAdapter")
include("KCore")
include("KEngine")
include("KFrameworkAI")
include("KUnitTestGoogle")

print("Project Generation done...")
  