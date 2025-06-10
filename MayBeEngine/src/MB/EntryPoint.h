#pragma once

#ifdef MB_PLATFORM_WINDOWS

extern MB::Application* MB::CreateApplication();

int main(int argc, char** argv)
{
	MB::Log::Init();
	MB_CORE_WARN("Initialized Log!");
	int a = 5;
	MB_INFO("Hello! Var={0}", a);

	auto app = MB::CreateApplication();
	app->Run();
	delete app;
}

#endif