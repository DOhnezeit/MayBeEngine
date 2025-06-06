#pragma once

#ifdef MBE_PLATFORM_WINDOWS

extern MBE::Application* MBE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = MBE::CreateApplication();
	app->Run();
	delete app;
}

#endif