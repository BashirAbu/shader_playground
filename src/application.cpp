#include "application.h"
#include "renderer/render_command.h"
#include "renderer/renderer_api.h"
#include "renderer/renderer_backend.h"
#include "ImGui/spg_imgui.h"
#include "editor_window.h"
#include "viewport_window.h"
#include "file_system.h"
#include <chrono>


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
		_mainWindow = std::shared_ptr<Window>(Window::Create(windowSpecs));
		RendererAPI* api = RendererAPI::Create();


		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		SPGImGui::InitPlatform(_mainWindow->GetPlatformWindowHandle());
		ImGui::StyleColorsDark();


	}
	Application::~Application()
	{
		SPG::SPGImGui::Shutdown();
		delete SPG::RendererBackend::GetSingleton();
		delete SPG::RendererAPI::GetSingleton();
		delete SPG::FileSystem::GetSingleton();
	}

	void Application::Init()
	{
		_viewportWindow = std::make_unique<ViewportWidnow>();
		_editorWindow = std::make_unique<EditorWidnow>();
	}


	void Application::Run()
	{
		std::chrono::time_point start_time = std::chrono::high_resolution_clock::now();
        std::chrono::time_point end_time = start_time;
		_deltaTime = 0.0167f;
		Init();
		while(_mainWindow->IsWindowRunning())
		{
			_time += _deltaTime;
			_renderedFrames += uint32_t(1.0f / _deltaTime);
			_mainWindow->PollEvents();
			SPG::RenderCommand::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			RenderCommand::Clear();
			SPG::SPGImGui::NewFrame();

			ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
			if (ImGui::BeginMainMenuBar()) {
				if (ImGui::BeginMenu("File")) 
				{
					if(ImGui::MenuItem("Load Project"))
					{
						std::string filepath = FileSystem::OpenFileDialog(0);
			        	SPG_LOG_MESSAGE("%s", filepath.c_str());
					}
					if(ImGui::MenuItem("Exit"))
					{
						Quit();
					}

					ImGui::EndMenu();
				}
				
				ImGui::EndMainMenuBar();
    		}

			
			_editorWindow->Show();
			_viewportWindow->Show();
			//ImGui::Begin("Console");
			//ImGui::End();
			//ImGui::ShowDemoWindow();

			SPG::SPGImGui::EndFrame();
			_mainWindow->SwapBackBuffer();

			end_time = std::chrono::high_resolution_clock::now();
            _deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1000000000.0f;
            start_time = end_time;
		} 

	}
	
	void Application::Quit()
	{
		_mainWindow->Quit();
	}
	
	const Vector2i Application::GetViewportFramebufferSize()
	{
		return _singleton->_viewportWindow->GetFramebufferSize();
	}
	
	const float Application::GetDeltaTime()
	{
		return _singleton->_deltaTime;
	}
	
	const float Application::GetTime()
	{
		return _singleton->_time;
	}
	
	const uint32_t Application::GetNumberOfRenderedFrames()
	{
		return _singleton->_renderedFrames;
	}
	
	char* Application::GetScriptBuffer()
	{
		return _singleton->_editorWindow->GetScriptBuffer();
	}

	Application* Application::GetSingleton()
	{
		assert(_singleton != nullptr);
		return _singleton;
	}
	
}