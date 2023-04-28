#include "application.h"
int main()
{
	
	SPG::ApplicationSpecs specs;
	SPG::Application* app = SPG::Application::Create(specs);
	app->Run();
	delete app;
    return 0;
}
