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

	};
	class Application
	{
	public:
		static Application* Create(const ApplicationSpecs& specs);
		~Application();

		Application* GetSingleton();
		void Run();
	private:
		Application(const ApplicationSpecs& specs);
	public:

	private:
		std::unique_ptr<Window> _window;
		static Application* _singleton;
	};
}