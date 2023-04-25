#pragma once
#include "core.h"
#include "ImGui/spg_imgui.h"
#include "renderer/framebuffer.h"
#include "renderer/shader.h"
#include "renderer/vertex_array.h"
#include "renderer/buffer.h"
namespace SPG
{
    class Surface
    {
    public:
        Surface();
        ~Surface();
        void Render();

        //uniforms:
        //-time
        //-delta time
        //-resolution
    private:
        std::shared_ptr<Shader> _shader;
        std::shared_ptr<VertexArray> _vertexArray;
        std::shared_ptr<VertexBuffer> _vertexBuffer;
        std::shared_ptr<IndexBuffer> _indexBuffer;
    };
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
        float _aspectRatio = 16.0f / 9.0f;

        std::shared_ptr<Surface> _surface;
    };
}