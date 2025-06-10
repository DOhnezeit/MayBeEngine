#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#ifndef MB_BUILD_DLL
#error "MB_BUILD_DLL is not defined in DLL build!"
#endif

#ifndef MB_PLATFORM_WINDOWS
#error "MB_PLATFORM_WINDOWS is not defined in DLL build!"
#endif

namespace MB
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MB_TRACE(e.ToString());
		}
		else if (e.IsInCategory(EventCategoryInput))
		{
			MB_TRACE(e.ToString());
		}

		while (true);
	}
}



