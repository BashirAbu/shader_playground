#pragma once
#include "core.h"
#include "window.h"
#include "math/spg_maths.h"
namespace SPG
{
	class EditorWidnow;
	class ViewportWidnow;
	struct ApplicationSpecs
	{
		wchar_t* title = L"Shader Playground";
		int32_t width = 1280;
		int32_t height = 720;
		int32_t windowPosX = 600;
		int32_t windowPosY = 200;

	};
	struct Settings
	{
		bool vsync = true;
		Vector2i framebufferSize = {1280, 720};
		Vector4f fontColor = {1, 1, 1, 1};
	};
	class Application
	{
	public:
		static Application* Create(const ApplicationSpecs& specs);
		~Application();
		Application* GetSingleton();
		void Init();
		void Run();
		void Quit();
		void LoadProject(std::string projectPath);
		void SaveProjectAs();
		void SaveProject();
		void ApplySettings();
		static const Vector2i GetViewportFramebufferSize();
		static const float GetDeltaTime();
		static const float GetTime();
		static const uint32_t GetNumberOfRenderedFrames();
		static char* GetScriptBuffer();
		static const std::string& GetProjectPath();
		static const Settings& GetSettings();
	private:
		Application(const ApplicationSpecs& specs);
		std::string BuildProjectFile();
	public:
		Settings settings;
	private:
		bool _openSettings = false;
		Settings _tempSettings;
		float _time = 0.0f, _deltaTime = 0.0f;
		uint32_t _renderedFrames = 0;
		std::shared_ptr<Window> _mainWindow;
		std::unique_ptr<EditorWidnow> _editorWindow;
		std::unique_ptr<ViewportWidnow> _viewportWindow;
		std::string _projectPath = "";
		static Application* _singleton;
	};

	
}