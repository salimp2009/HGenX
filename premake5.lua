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
IncludeDir["Glad"] = "HGenX/vendor/Glad/include"
IncludeDir["ImGui"] = "HGenX/vendor/imgui"
IncludeDir["glm"] = "HGenX/vendor/glm"

include "HGenX/vendor/GLFW"
include "HGenX/vendor/Glad"
include "HGenX/vendor/imgui"

project	"HGenX"
	location "HGenX"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hgpch.h"
	pchsource "HGenX/src/hgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp", 
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"	
		systemversion "latest"

	defines
	{
		"HG_PLATFORM_WINDOWS",
		"HG_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	filter "configurations:Debug"
		defines "HG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HG_RELEASE"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "HG_DIST"
		runtime "Release"
		optimize "on"			

	project	"Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

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
		"HGenX/src",
		"HGenX/vendor",
		"%{IncludeDir.glm}"

	}

	links
	{
		"HGenX"
	}

	filter "system:windows"	
	systemversion "latest"

	defines
	{
		"HG_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "HG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HG_RELEASE"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "HG_DIST"
		runtime "Release"
		optimize "on"			