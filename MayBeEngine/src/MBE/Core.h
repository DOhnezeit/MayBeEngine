#pragma once
// This file will include macros and other necessary includes for the MBE core functionality.

#ifdef MBE_PLATFORM_WINDOWS
	#ifdef MBE_BUILD_DLL
		#define MBE_API __declspec(dllexport)
	#else
		#define MBE_API __declspec(dllimport)
	#endif 
#else
	#error MBE only supports Windows!
#endif
 