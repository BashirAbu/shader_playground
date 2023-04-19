#pragma once
#include "core.h"
#include <Windows.h>
namespace SPG
{
	struct WindowSpecs
	{
		wchar_t* title = L"Shader Playground";
		int32_t width = 1280;
		int32_t height = 720;
		int32_t windowPosX = 600;
		int32_t windowPosY = 200;
	};
	class Window
	{
	public:
		static Window* Create(const WindowSpecs& specs);
		virtual ~Window(){}
		virtual void* GetPlatformWindowHandle() = 0;
		virtual void PollEvents() = 0;
		virtual const bool IsWindowRunning() const = 0;
	protected:
	};
}