#ifdef SPG_WINDOWS
#include "window.h"
#ifdef SPG_WINDOWS
#include "platform/win32/win32_window.h"
#endif
namespace SPG
{
	Window* Window::Create(const ApplicationSpecs& specs)
	{
		Window* window = nullptr;
#ifdef SPG_WINDOWS
		window = new Win32Window(specs);
#endif
		return window;
	}
}
#endif