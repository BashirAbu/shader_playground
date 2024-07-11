#include "application.h"
#include "renderer/render_command.h"
#include "renderer/renderer_api.h"
#include "renderer/renderer_backend.h"
#include "ImGui/spg_imgui.h"
#include "editor_window.h"
#include "viewport_window.h"
#include "file_system.h"
#include <chrono>
#include "tinyxml2/tinyxml2.h"

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

		io.Fonts->AddFontFromFileTTF("data/Roboto-Medium.ttf", 16);
		//style
		ImGuiStyle& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_Text]                  = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_Border]                = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
		style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
		style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
		style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
		style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
		style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.08f, 0.50f, 0.72f, 1.00f);
		style.Colors[ImGuiCol_Button]                = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
		style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
		style.Colors[ImGuiCol_Header]                = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
		style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
		style.Colors[ImGuiCol_Separator]             = style.Colors[ImGuiCol_Border];
		style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
		style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
		style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		style.Colors[ImGuiCol_Tab]                   = ImVec4(0.08f, 0.08f, 0.09f, 0.83f);
		style.Colors[ImGuiCol_TabHovered]            = ImVec4(0.33f, 0.34f, 0.36f, 0.83f);
		style.Colors[ImGuiCol_TabActive]             = ImVec4(0.23f, 0.23f, 0.24f, 1.00f);
		style.Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
		style.Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_DockingPreview]        = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
		style.Colors[ImGuiCol_DockingEmptyBg]        = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
		style.Colors[ImGuiCol_NavHighlight]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		style.Colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		style.Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
		style.GrabRounding                           = style.FrameRounding = 2.3f;

		
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
		_viewportWindow->GetSurface()->RecompileShader();
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
			
			DrawMainMenu();
			
			HandleSettingsPopup();
			
			if(_openSettings)
			{
				ImGui::OpenPopup("Settings");
				ImGui::SetWindowSize({512, 512});
			}
			ImGuiWindowFlags settingPopUpFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
			
			if (ImGui::BeginPopupModal("Settings", nullptr , settingPopUpFlags)) 
			{
				ImVec2 windowSize = ImGui::GetContentRegionAvail();

 				ImGui::Text("Vsync:");
				ImGui::SameLine();
				ImGui::Checkbox("##", &(_tempSettings.vsync));

				ImGui::Text("Framebuffer Size:");
				ImGui::SameLine();
				ImGui::InputInt2("##", (_tempSettings.framebufferSize.elements));


				ImGui::Text("Font Color:");
				ImGui::SameLine();
				ImGui::ColorEdit3("##", (_tempSettings.fontColor.elements));

				ImGui::SetCursorPos({windowSize.x - 80, windowSize.y});
				if (ImGui::Button("Cancel")) {
					ImGui::CloseCurrentPopup();
					_openSettings = false;
					_tempSettings.fontColor = settings.fontColor;
					_tempSettings.framebufferSize = settings.framebufferSize;
					_tempSettings.vsync = settings.vsync;
				}
				ImGui::SameLine();
				if(ImGui::Button("OK"))
				{
					if(_tempSettings.framebufferSize.X < 0 || _tempSettings.framebufferSize.Y < 0)
					{
						SPG_LOG_ERROR("Framebuffer width and height cannot be less than 0!");
					}
					else
					{
						settings.fontColor = _tempSettings.fontColor;
						settings.framebufferSize = _tempSettings.framebufferSize;
						settings.vsync = _tempSettings.vsync;
						ImGui::CloseCurrentPopup();
						_openSettings = false;
						ApplySettings();
					}
				}

				ImGui::EndPopup();
			}
			_editorWindow->Show();
			_viewportWindow->Show();
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
	
	void Application::LoadProject(std::string projectPath)
	{
		if(projectPath.length() == 0)
			return;
		const char* extension = strrchr(projectPath.c_str(), '.');
		if(strcmp(extension, ".shader_playground") !=0)
		{
			SPG_LOG_ERROR("Not Supported File Format. %s", projectPath.c_str());
			return;
		}
		FileData data = FileSystem::OpenFile(projectPath.c_str());
		char* loadedText = (char*)(data.data);
		tinyxml2::XMLDocument xmlDoc;
		tinyxml2::XMLError result = xmlDoc.Parse(loadedText);
		if (result != tinyxml2::XML_SUCCESS) 
		{
			SPG_LOG_ERROR("Error reading project file!");
			return;
   		}
		tinyxml2::XMLElement* projectElement = xmlDoc.FirstChildElement("project");
		tinyxml2::XMLElement* scriptElement = projectElement->FirstChildElement("script");
		const char* script = scriptElement->GetText();

		tinyxml2::XMLElement* settingsElement = projectElement->FirstChildElement("settings");
		settings.vsync = strcmp(settingsElement->FirstChildElement("vsync")->GetText(), "on") == 0? true : false; 

		settingsElement->FirstChildElement("framebufferSize")->FirstChildElement("width")->QueryIntText(&(settings.framebufferSize.X));
		settingsElement->FirstChildElement("framebufferSize")->FirstChildElement("height")->QueryIntText(&(settings.framebufferSize.Y));


		tinyxml2::XMLElement* colorElement = settingsElement->FirstChildElement("font")->FirstChildElement("color");
		colorElement->FirstChildElement("red")->QueryFloatText(&(settings.fontColor.X));
		colorElement->FirstChildElement("green")->QueryFloatText(&(settings.fontColor.Y));
		colorElement->FirstChildElement("blue")->QueryFloatText(&(settings.fontColor.Z));


		_editorWindow->SetScriptBuffer((void*)script, strlen(script));
		_viewportWindow->OnFramebufferSizeChange();
		_projectPath = projectPath;
		_tempSettings = settings;
		std::string title = "Shader Playground - " +  projectPath;
		_mainWindow->UpdateWindowTitle(title.c_str());
	}
	
	void Application::SaveProjectAs()
	{
		_projectPath = FileSystem::SaveAsDialog(_mainWindow->GetPlatformWindowHandle());
		if(_projectPath != "")
		{
			const char* extension = strrchr(_projectPath.c_str(), '.');
			if(!extension)
			{
				_projectPath = _projectPath + ".shader_playground";
			}
			SaveProject();
		}
	}
	
	void Application::SaveProject()
	{
		if(_projectPath != "")
		{
			std::string projectFile = BuildProjectFile();
			FileSystem::WriteToFile(_projectPath.c_str(), (void*)projectFile.c_str(), projectFile.length() + 1, OpenMode::Overwrite);
		}
	}
	
	void Application::ApplySettings()
	{
		
		_viewportWindow->OnFramebufferSizeChange();
		//vsync.
		RendererBackend::GetSingleton()->SetVsync(settings.vsync);
		//font color.
	}
	std::string Application::BuildProjectFile()
	{
		std::string result;
		const char* buffer =  _editorWindow->GetScriptBuffer();
		
		tinyxml2::XMLDocument xmlDoc;
		
		tinyxml2::XMLElement* rootElement = xmlDoc.NewElement("project");
		tinyxml2::XMLElement* settingsElement = rootElement->InsertNewChildElement("settings");
		tinyxml2::XMLElement* vsyncElement = settingsElement->InsertNewChildElement("vsync");
		vsyncElement->SetText(settings.vsync? "on" : "off");

		tinyxml2::XMLElement* framebufferSizeElement = settingsElement->InsertNewChildElement("framebufferSize");
		tinyxml2::XMLElement* framebufferWidthElement = framebufferSizeElement->InsertNewChildElement("width");
		framebufferWidthElement->SetText(settings.framebufferSize.X);
		tinyxml2::XMLElement* framebufferHeightElement = framebufferSizeElement->InsertNewChildElement("height");
		framebufferHeightElement->SetText(settings.framebufferSize.Y);

		tinyxml2::XMLElement* fontElement = settingsElement->InsertNewChildElement("font");

		tinyxml2::XMLElement* fontColorElement = fontElement->InsertNewChildElement("color");
		tinyxml2::XMLElement* fontColorRedElement = fontColorElement->InsertNewChildElement("red");
		fontColorRedElement->SetText(settings.fontColor.X);
		tinyxml2::XMLElement* fontColorGreenElement = fontColorElement->InsertNewChildElement("green");
		fontColorGreenElement->SetText(settings.fontColor.Y);
		tinyxml2::XMLElement* fontColorBlueElement = fontColorElement->InsertNewChildElement("blue");
		fontColorBlueElement->SetText(settings.fontColor.Z);

		tinyxml2::XMLElement* scriptElement = rootElement->InsertNewChildElement("script");
		tinyxml2::XMLText* codeText = xmlDoc.NewText(buffer);
		codeText->SetCData(true);
		scriptElement->InsertEndChild(codeText);

		xmlDoc.InsertFirstChild(rootElement);

		tinyxml2::XMLPrinter printer;

		xmlDoc.Print(&printer);
		result = printer.CStr();
		return result;
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
	
	const std::string& Application::GetProjectPath()
	{
		return _singleton->_projectPath;
	}
	
	const Settings& Application::GetSettings()
	{
		return _singleton->settings;
	}

	Application* Application::GetSingleton()
	{
		assert(_singleton != nullptr);
		return _singleton;
	}
	void DrawMainMenu() {
	    if (!ImGui::BeginMainMenuBar())
	        return;
	
	    if (ImGui::BeginMenu("File")) {
	        DrawFileMenu();
	        ImGui::EndMenu();
	    }
	
	    ImGui::EndMainMenuBar();
	}
	
	void DrawFileMenu() {
	    if (ImGui::MenuItem("Load Project")) {
	        LoadProject(FileSystem::OpenFileDialog(0));
	    }
	    if (ImGui::MenuItem("Save")) {
	        if (_projectPath.empty()) {
	            SaveProjectAs();
	        } else {
	            SaveProject();
	        }
	    }
	    ImGui::Separator(); // Optional separator
	    if (ImGui::MenuItem("Save As...")) {
	        SaveProjectAs();
	    }
	    ImGui::Separator(); // Optional separator
	    if (ImGui::MenuItem("Exit")) {
	        Quit();
	    }
	}
	
	void HandleSettingsPopup() {
	    if (_openSettings) {
	        ImGui::OpenPopup("Settings");
	        ImGui::SetWindowSize({512, 512});
	    }
	
	    ImGuiWindowFlags settingPopUpFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
	
	    if (ImGui::BeginPopupModal("Settings", nullptr, settingPopUpFlags)) {
	        DrawSettingsPopup();
	        ImGui::EndPopup();
	    }
	}
	
	void DrawSettingsPopup() {
	    ImVec2 windowSize = ImGui::GetContentRegionAvail();
	
	    ImGui::Text("Vsync:");
	    ImGui::SameLine();
	    ImGui::Checkbox("##VsyncCheckbox", &_tempSettings.vsync);
	
	    ImGui::Text("Framebuffer Size:");
	    ImGui::SameLine();
	    ImGui::InputInt2("##FramebufferSizeInput", _tempSettings.framebufferSize.elements);
	
	    ImGui::Text("Font Color:");
	    ImGui::SameLine();
	    ImGui::ColorEdit3("##FontColorEdit", _tempSettings.fontColor.elements);
	
	    ImGui::SetCursorPos({windowSize.x - 80, windowSize.y});
	    if (ImGui::Button("Cancel")) {
	        CancelSettingsChanges();
	    }
	    ImGui::SameLine();
	    if (ImGui::Button("OK")) {
	        ApplySettingsChanges();
	    }
	}
	
	void CancelSettingsChanges() {
	    ImGui::CloseCurrentPopup();
	    _openSettings = false;
	    // Restore original settings
	    _tempSettings = settings; // Assuming `_tempSettings` and `settings` are structs or classes
	}
	
	void ApplySettingsChanges() {
	    if (_tempSettings.framebufferSize.x < 0 || _tempSettings.framebufferSize.y < 0) {
	        SPG_LOG_ERROR("Framebuffer width and height cannot be less than 0!");
	    } else {
	        settings = _tempSettings; // Apply new settings
	        ImGui::CloseCurrentPopup();
	        _openSettings = false;
	        ApplySettings();
	    }
	}
	
}
