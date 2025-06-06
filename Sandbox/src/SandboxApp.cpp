#include <MBE.h>

class Sandbox : public MBE::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

MBE::Application* MBE::CreateApplication()
{
	return new Sandbox();
}
