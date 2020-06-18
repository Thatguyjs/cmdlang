workspace "CmdLang"
	configurations { "Debug", "Release" }

project "CmdLang"
	kind "ConsoleApp"
	language "C++"
	targetdir "build/%{cfg.buildcfg}"

	systemversion "latest"

	files { "**.h", "**.cpp" }

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
