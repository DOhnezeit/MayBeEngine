workspace "MayBeEngine"
    architecture "x64"

    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "MayBeEngine/external/spdlog/include"
IncludeDir["MB"] = "MayBeEngine/src"

filter { "language:C++", "system:windows" }
    buildoptions { "/utf-8" }

project "MayBeEngine"
    location "MayBeEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "MBpch.h"
    pchsource "MayBeEngine/src/MBpch.cpp"

    includedirs
    {
	    IncludeDir["spdlog"],
    	IncludeDir["MB"]
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MB_PLATFORM_WINDOWS",
            "MB_BUILD_DLL"
        }

        postbuildcommands
        {
            "{COPYFILE} %{cfg.buildtarget.abspath} ../bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox/%{prj.name}.dll"
        }

    filter "configurations:Debug"
        defines { "MB_DEBUG" }
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
	defines { "MB_RELEASE" }
	optimize "On"

    filter "configurations:Dist"
	defines { "MB_DIST" }
	optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
	IncludeDir["spdlog"],
	IncludeDir["MB"]
    }

    links { "MayBeEngine" }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "MB_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines { "MB_DEBUG" }
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines { "MB_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "MB_DIST" }
        optimize "On"