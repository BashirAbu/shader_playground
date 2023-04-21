#include "application.h"
#include "renderer/render_command.h"
#include "renderer/renderer_api.h"
#include "renderer/renderer_backend.h"
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
		_mainWindow = std::unique_ptr<Window>(Window::Create(windowSpecs));

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
	}
	void Application::Run()
	{
		while(_mainWindow->IsWindowRunning())
		{
			_mainWindow->PollEvents();
			SPG::RenderCommand::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			RenderCommand::Clear();
			SPG::SPGImGui::NewFrame();

			
 			ImGuiWindowFlags window_flags = 0;
			const ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->WorkPos);
			ImGui::SetNextWindowSize(viewport->WorkSize);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
			window_flags &= ~ImGuiWindowFlags_MenuBar;
			bool open = true;
			ImGui::Begin("MyWindow", &open, window_flags);
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id);
			ImGui::End();
			ImGui::PopStyleVar();
			window_flags = 0;
			ImGui::Begin("Window 1", &open, window_flags);
			ImGui::End();

			ImGui::Begin("Window 2");
			ImGui::End(); 

			ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
			if (ImGui::BeginMainMenuBar()) {
				if (ImGui::BeginMenu("File")) 
				{
					if(ImGui::MenuItem("Exit"))
					{
						Quit();
					}

					ImGui::EndMenu();
				}
				ImGui::EndMainMenuBar();
    		}
			ImGui::Begin("Window 1");
			ImGui::End(); 

			ImGui::Begin("Window 2");
			ImGui::End(); 
			SPG::SPGImGui::EndFrame();
			_mainWindow->SwapBackBuffer();
		} 

	}
	
	void Application::Quit()
	{
		_mainWindow->Quit();
	}

	Application* Application::GetSingleton()
	{
		assert(_singleton != nullptr);
		return _singleton;
	}
}