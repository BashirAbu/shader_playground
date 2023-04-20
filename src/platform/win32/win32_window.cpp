#include "win32_window.h"
#include "renderer/renderer_backend.h"
#include "renderer/render_command.h"
namespace SPG
{
    LRESULT WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
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
			RendererBackendSpecs specs;
			specs.internalWindowHandle = (void*)hWnd;
			if(!RendererBackend::Create(specs))
			{
				//change context or somehting.
			}

        }break;
        case WM_SIZE: 
		{
			if (wndData)
			{
				UINT width = LOWORD(lParam);
				UINT height = HIWORD(lParam);
				wndData->width = width;
				wndData->height = height;
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
        windowClass.lpfnWndProc = WindowProc;
        windowClass.hInstance = hInstance;
        windowClass.lpszClassName = specs.title;
        windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        RegisterClassW(&windowClass );
        RECT windowSize = { 0 };
        windowSize.left = 0;
        windowSize.right = specs.width;
        windowSize.top = 0;
        windowSize.bottom = specs.height;
		_windowStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
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

        assert(_hwnd);
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
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}
	
	void Win32Window::SwapBackBuffer()
	{
		SwapBuffers(_hdc);
	}
	
	const bool Win32Window::IsWindowRunning() const
	{
		return _windowData.running;
	}
}