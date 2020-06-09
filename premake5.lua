workspace "HGenX"			
	architecture "x64"
	startproject "Sandbox"
	

	configurations
	{
		"Debug",
		"Release",		
		"Dist"			 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "HGenX/vendor/GLFW/include"

include "HGenX/vendor/GLFW"

project	"HGenX"
	location "HGenX"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hgpch.h"
	pchsource "HGenX/src/hgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp", 
	}
 
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"		
		systemversion "latest"

	defines
	{
		"HG_PLATFORM_WINDOWS",
		"HG_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "HG_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HG_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "On"	

	filter "configurations:Dist"
		defines "HG_DIST"
		buildoptions "/MD"
		runtime "Release"
		optimize "On"			

	project	"Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp", 
	}

	includedirs
	{
		"HGenX/vendor/spdlog/include",
		"HGenX/src"
	}

	links
	{
		"HGenX"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"		
		systemversion "latest"

	defines
	{
		"HG_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "HG_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HG_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "On"	

	filter "configurations:Dist"
		defines "HG_DIST"
		buildoptions "/MD"
		runtime "Release"
		optimize "On"			