#include <MB.h>

class Sandbox : public MB::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

MB::Application* MB::CreateApplication()
{
	return new Sandbox();
}
