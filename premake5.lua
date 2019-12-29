include "conanbuildinfo.premake.lua"

workspace "UndertaleEngine"
    conan_basic_setup()
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release"
    }

    project "utengine"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir "build/bin/%{prj.name}-%{cfg.buildcfg}"
        objdir "build/obj/%{prj.name}-%{cfg.buildcfg}"
        linkoptions { conan_exelinkflags }

        files
        {
            "includes/**.h",
            "src/**.cpp"
        }

        includedirs
        {
            "includes"
        }

        filter "configurations:Debug"
            defines "UT_DEBUG"
            runtime "Debug"
            symbols "on"
        
        filter "configurations:Release"
            defines "UT_RELEASE"
            runtime "Release"
            optimize "on"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir "build/bin/%{prj.name}-%{cfg.buildcfg}"
        objdir "build/obj/%{prj.name}-%{cfg.buildcfg}"

        files
        {
            "%{prj.name}/includes/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/includes",
            "includes/"
        }

        links
        {
            "utengine"
        }

		filter "system:windows"
			postbuildcommands { "{COPY} %{conan_rootpath_sfml}/bin/openal32.dll %{cfg.targetdir}" }

        filter "configurations:Debug"
            defines "UT_DEBUG"
            runtime "Debug"
            symbols "on"
        
        filter "configurations:Release"
            defines "UT_RELEASE"
            runtime "Release"
            optimize "on"