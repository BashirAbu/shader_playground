#ifdef SPG_WINDOWS
#include <Windows.h>
#include "ImGui/spg_imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_opengl3.h"
// Copy this line into your .cpp file to forward declare the function.
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace SPG
{
    void SPGImGui::InitPlatform(void* platformWindowHandle)
    {
		ImGui_ImplWin32_Init(platformWindowHandle);
		ImGui_ImplOpenGL3_Init("#version 130");
    }

    void SPGImGui::NewFrame() 
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

	}
	void SPGImGui::EndFrame()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void SPGImGui::Shutdown()
    {
		ImGuiIO& io = ImGui::GetIO();
		//For some reason heob64.exe says io.BackendPlatformUserData is not freed. my brain
		free(io.BackendPlatformUserData);
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
		//ImGui_ImplWin32_Shutdown();
    }
	void SPGImGui::PollEvents()
    {
        MSG msg = {0};
		HWND focusWindow = GetFocus();
		while(PeekMessageW(&msg, focusWindow, 0, 0, PM_REMOVE) > 0)
		{
			ImGui_ImplWin32_WndProcHandler(focusWindow, msg.message, msg.wParam, msg.lParam);
		}
    }
}
#endif
