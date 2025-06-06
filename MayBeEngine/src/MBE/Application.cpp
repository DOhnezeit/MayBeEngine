
#include "Application.h"

#ifndef MBE_BUILD_DLL
#error "MBE_BUILD_DLL is not defined in DLL build!"
#endif

#ifndef MBE_PLATFORM_WINDOWS
#error "MBE_PLATFORM_WINDOWS is not defined in DLL build!"
#endif

namespace MBE
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true);
	}
}



