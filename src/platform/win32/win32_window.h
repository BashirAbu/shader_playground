#pragma once
#ifdef SPG_WINDOWS
#include "core.h"
#include "window.h"
namespace SPG
{
	struct WindowData
	{
		int32_t width;
		int32_t height;
		bool running;
	};
	class Win32Window : public Window
	{
	public:
		Win32Window(const WindowSpecs& specs);
		~Win32Window();
		virtual void* GetPlatformWindowHandle();
		virtual void PollEvents();
        virtual void SwapBackBuffer();
		virtual void Quit();
		const bool IsWindowRunning() const;
	private:
		WindowData _windowData;
		DWORD _windowStyle = 0;
		HDC _hdc;
		HWND _hwnd; 
	};
}
#endif
