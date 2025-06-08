#pragma once

#ifdef MBE_PLATFORM_WINDOWS

extern MBE::Application* MBE::CreateApplication();

int main(int argc, char** argv)
{
	MBE::Log::Init();
	MBE_CORE_WARN("Initialized Log!");
	int a = 5;
	MBE_INFO("Hello! Var={0}", a);

	auto app = MBE::CreateApplication();
	app->Run();
	delete app;
}

#endif