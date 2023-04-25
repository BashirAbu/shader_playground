#include "viewport_window.h"
#include "renderer/render_command.h"
namespace SPG
{
    ViewportWidnow::ViewportWidnow()
    {
        _viewPortFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
        FramebufferSpecs framebufferSpecs = {500, 500};
        
        _framebuffer = std::shared_ptr<Framebuffer>(Framebuffer::Create(framebufferSpecs));
        TextureSpecs renderTexSpecs;
        _renderTex = std::shared_ptr<Texture>(Texture::Create(renderTexSpecs));
    }

    ViewportWidnow::~ViewportWidnow()
    {
        
    }
    void ViewportWidnow::Show()
    {
       
        ImGui::Begin("Viewport");
        { 
            {
                RenderCommand::SetViewportSize(_framebuffer->GetColorAttachment()->GetSize().X, _framebuffer->GetColorAttachment()->GetSize().Y);
                _framebuffer->Bind();
                RenderCommand::SetClearColor(1.0f, 1.0f, 0.0f, 1.0f);
                RenderCommand::Clear();
                _framebuffer->Unbind();
                ImGuiViewport* viewPort = ImGui::GetMainViewport();
                RenderCommand::SetViewportSize((int32_t)viewPort->Size.x, (int32_t)viewPort->Size.y);
            }
            _renderTex->UpdateData((void*)_framebuffer->GetColorAttachment()->GetTextureData(), 200, 200);
            ImGui::Image((void*)(intptr_t)_renderTex->GetID(), {100, 100});            
        }
        ImGui::End(); 
    }
}