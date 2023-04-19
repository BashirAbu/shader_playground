#pragma once
#ifdef SPG_WINDOWS
#include "core.h"
#include "window.h"
namespace SPG
{
	class Win32Window : public Window
	{
	public:
		Win32Window(const ApplicationSpecs& specs);
		~Win32Window();

		HWND hwnd;

	};
}
#endif
