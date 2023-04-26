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
	class Application
	{
	public:
		static Application* Create(const ApplicationSpecs& specs);
		~Application();
		Application* GetSingleton();
		void Init();
		void Run();
		void Quit();
		static const Vector2i GetViewportFramebufferSize();
		static const float GetDeltaTime();
		static const float GetTime();
		static const uint32_t GetNumberOfRenderedFrames();
		static char* GetScriptBuffer();
	private:
		Application(const ApplicationSpecs& specs);
	public:

	private:
		float _time = 0.0f, _deltaTime = 0.0f;
		uint32_t _renderedFrames = 0;
		std::unique_ptr<Window> _mainWindow;
		std::unique_ptr<EditorWidnow> _editorWindow;
		std::unique_ptr<ViewportWidnow> _viewportWindow;
		static Application* _singleton;
	};
}