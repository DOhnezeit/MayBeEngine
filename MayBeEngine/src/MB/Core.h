#pragma once
// This file will include macros and other necessary includes for the MB core functionality.

#ifdef MB_PLATFORM_WINDOWS
	#ifdef MB_BUILD_DLL
		#define MB_API __declspec(dllexport)
	#else
		#define MB_API __declspec(dllimport)
	#endif 
#else
	#error MB only supports Windows!
#endif

#define BIT(x) (1 << x)