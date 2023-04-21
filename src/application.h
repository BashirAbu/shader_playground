#pragma once
#include "core.h"
#include "window.h"
namespace SPG
{
	struct ApplicationSpecs
	{
		wchar_t* title = L"Shader Playground";
		int32_t width = 1280;
		int32_t height = 720;
		int32_t windowPosX = 600;
		int32_t windowPosY = 200;

	};
	class Application
	{
	public:
		static Application* Create(const ApplicationSpecs& specs);
		~Application();

		Application* GetSingleton();
		void Run();
		void Quit();
	private:
		Application(const ApplicationSpecs& specs);
	public:

	private:
		std::unique_ptr<Window> _mainWindow;
		static Application* _singleton;
	};
}