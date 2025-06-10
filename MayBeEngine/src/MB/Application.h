#pragma once

#include "Core.h"

namespace MB
{
	class MB_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client application
	Application* CreateApplication();

}



