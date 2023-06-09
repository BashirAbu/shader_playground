#pragma once
#include "core.h"
#include <Windows.h>
namespace SPG
{
	enum class WindowStyle
	{
		default = 0,
		PopUp
	};
	struct WindowSpecs
	{
		wchar_t* title = L"Shader Playground";
		int32_t width = 1280;
		int32_t height = 720;
		int32_t windowPosX = 600;
		int32_t windowPosY = 200;
		WindowStyle style = WindowStyle::default;
	};
	class Window
	{
	public:
		static Window* Create(const WindowSpecs& specs);
		virtual ~Window(){}
		virtual void* GetPlatformWindowHandle() = 0;
		virtual void PollEvents() = 0;
		virtual const bool IsWindowRunning() const = 0;
        virtual void SwapBackBuffer() = 0;
		virtual void Quit() = 0;
		virtual void UpdateWindowTitle(const char* title) = 0;
	protected:
	};
}