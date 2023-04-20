#ifdef SPG_WINDOWS
#include "ImGui/spg_imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_opengl3.h"
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
}
#endif
