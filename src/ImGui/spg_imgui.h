#pragma once
#include "core.h"
#include "imgui.h"
namespace SPG
{
    class SPGImGui
    {
    public:
        static void InitPlatform(void* platformWindowHandle);

		static void NewFrame();
		static void EndFrame();

        static void Shutdown();
    private:

    };
}