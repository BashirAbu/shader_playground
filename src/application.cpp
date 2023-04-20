#include "application.h"
#include "renderer/render_command.h"
#include "renderer/renderer_api.h"
#include "ImGui/spg_imgui.h"
namespace SPG
{
	Application* Application::_singleton = nullptr;


	Application* Application::Create(const ApplicationSpecs& specs)
	{
		if (!_singleton)
		{
			_singleton = new Application(specs);
		}

		return _singleton;
	}
	Application::Application(const ApplicationSpecs& specs)
	{
		WindowSpecs windowSpecs;
		windowSpecs.title = specs.title;
		windowSpecs.width = specs.width;
		windowSpecs.height = specs.height;
		_window = std::unique_ptr<Window>(Window::Create(windowSpecs));

		RendererAPI* api = RendererAPI::Create();
	}
	Application::~Application()
	{
	
	}
	void Application::Run()
	{
		while(_window->IsWindowRunning())
		{
			_window->PollEvents();
			RenderCommand::SetClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			RenderCommand::Clear();
			_window->SwapBackBuffer();
		}
	}

	Application* Application::GetSingleton()
	{
		assert(_singleton != nullptr);
		return _singleton;
	}
}