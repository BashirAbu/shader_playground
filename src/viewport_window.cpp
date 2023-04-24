#include "viewport_window.h"
#include "renderer/render_command.h"
namespace SPG
{
    ViewportWidnow::ViewportWidnow()
    {
        _viewPortFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
        FramebufferSpecs framebufferSpecs = {1280, 720};
        _framebuffer = std::shared_ptr<Framebuffer>(Framebuffer::Create(framebufferSpecs));
    }

    ViewportWidnow::~ViewportWidnow()
    {
        
    }
    void ViewportWidnow::Show()
    {
        {
            RenderCommand::SetViewportSize(1280, 720);
            _framebuffer->Bind();
            RenderCommand::SetClearColor(1.0f, 1.0f, 0.0f, 0.5f);
            RenderCommand::Clear();
            _framebuffer->Unbind();
            ImGuiViewport* v = ImGui::GetMainViewport();
            RenderCommand::SetViewportSize(v->Size.x, v->Size.y);

        }
        ImGui::Begin("ViewPort");
        { 
            ImVec2 size = ImGui::GetWindowSize();
            ImGui::Image((void*)(intptr_t)_framebuffer->GetColorAttachment()->GetID(), size);            
        }
        ImGui::End(); 
    }
}