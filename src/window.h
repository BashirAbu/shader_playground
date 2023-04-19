#pragma once
#include "core.h"
#include <Windows.h>
namespace SPG
{
	struct ApplicationSpecs;
	class Window
	{
	public:
		static Window* Create(const ApplicationSpecs& specs);
		virtual ~Window(){}

	protected:
	};
}