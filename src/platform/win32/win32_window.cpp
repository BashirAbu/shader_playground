#include "win32_window.h"
#include "renderer/renderer_backend.h"
#include "renderer/render_command.h"


// Copy this line into your .cpp file to forward declare the function.
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace SPG
{
    static LRESULT WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = 0;
		WindowData* wndData = (WindowData*)GetWindowLongPtrW(hWnd, GWLP_USERDATA);
		switch (message) {
        /*case WM_SYSCOMMAND:
        {
            return 0;
        }break;*/
        case WM_CREATE: 
		{
			if(!RendererBackend::GetSingleton())
			{		
				RendererBackendSpecs specs;
				specs.internalWindowHandle = (void*)hWnd;
				if(!RendererBackend::Create(specs))
				{
					//change context or somehting.
				}
			}

        }break;
        case WM_SIZE: 
		{
			if (wndData)
			{
				RECT clientRect;
				GetClientRect(hWnd, &clientRect);
				UINT width = clientRect.right - clientRect.left;
				UINT height = clientRect.bottom - clientRect.top;
				RenderCommand::SetViewportSize(width, height);
			}
        }break;
        case WM_CLOSE: {
			assert(wndData);
			wndData->running = false;
            result = 0;
        }break;
        case WM_DESTROY: {
            result = 0;
        }break;
        default: {
            result = DefWindowProc(hWnd, message, wParam, lParam);
        }break;
        }
        return result;
    }

	Win32Window::Win32Window(const WindowSpecs& specs)
	{
		_windowData = {0};
		_windowData.height = specs.height;
		_windowData.width = specs.width;


		HINSTANCE hInstance = GetModuleHandleA(0);
        WNDCLASSW windowClass = { 0 };
        windowClass.lpfnWndProc = (WNDPROC)WindowProc;
        windowClass.hInstance = hInstance;
        windowClass.lpszClassName = specs.title;
        windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        RegisterClassW(&windowClass );
		_windowStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
		_windowStyle |= specs.style == WindowStyle::PopUp? WS_POPUP : 0;
        RECT windowSize = { 0 };
        windowSize.left = 0;
        windowSize.right = specs.width;
        windowSize.top = 0;
        windowSize.bottom = specs.height;
		AdjustWindowRectEx(&windowSize, _windowStyle, 0, 0);
		_hwnd = CreateWindowExW(
			0,
			windowClass.lpszClassName,
			specs.title,
			_windowStyle,
			specs.windowPosX, specs.windowPosY, windowSize.right - windowSize.left, windowSize.bottom - windowSize.top,
			NULL,
			NULL,
			hInstance,
			NULL
		);

        //assert(_hwnd);
        ShowWindow(_hwnd, SW_SHOW);
		_windowData.running = true;
		SetWindowLongPtrW(_hwnd, GWLP_USERDATA, (LONG_PTR)&_windowData);
		_hdc = GetDC(_hwnd);
	}

	Win32Window::~Win32Window()
	{
		DestroyWindow(_hwnd);
	}

	void* Win32Window::GetPlatformWindowHandle()
	{
		return (void*)_hwnd;
	}

	void Win32Window::PollEvents()
	{
		MSG msg = {0};
		while(PeekMessageW(&msg, _hwnd, 0, 0, PM_REMOVE) > 0)
		{
			ImGui_ImplWin32_WndProcHandler(_hwnd, msg.message, msg.wParam, msg.lParam);
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}
	
	void Win32Window::SwapBackBuffer()
	{
		SwapBuffers(_hdc);
	}
	
	void Win32Window::Quit()
	{
		_windowData.running = false;
	}
	
	const bool Win32Window::IsWindowRunning() const
	{
		return _windowData.running;
	}
}