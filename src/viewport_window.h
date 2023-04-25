#pragma once
#include "core.h"
#include "ImGui/spg_imgui.h"
#include "renderer/framebuffer.h"
namespace SPG
{
    class ViewportWidnow
    {
        public:
        ViewportWidnow();
        ~ViewportWidnow();
        void Show();
        ImVec2 size;
        private:
        ImGuiWindowFlags _viewPortFlags = 0;
        std::shared_ptr<Framebuffer> _framebuffer;
        std::shared_ptr<Texture> _renderTex;
    };
}