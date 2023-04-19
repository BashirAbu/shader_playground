#include <stdio.h>
#include "application.h"
int main()
{
	SPG::ApplicationSpecs specs;
	SPG::Application* app = SPG::Application::Create(specs);
	app->Run();
	delete app;
	SPG_LOG_MESSAGE("hello SPG!");
    return 0;
}
