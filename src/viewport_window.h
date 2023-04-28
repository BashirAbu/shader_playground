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
        Surface(const Vector2i& framebufferSize);
        ~Surface();
        void Render();
        void Recreate();
        void RecompileShader();
        //uniforms:
        //-time
        //-delta time
        //-resolution
    private:
        std::shared_ptr<Shader> _shader;
        std::shared_ptr<VertexArray> _vertexArray;
        std::shared_ptr<VertexBuffer> _vertexBuffer;
        std::shared_ptr<IndexBuffer> _indexBuffer;
        char* _shaderBuffer;
    };
    class ViewportWidnow
    {
        public:
            ViewportWidnow();
            ~ViewportWidnow();
            void Show();
            const Vector2i& GetFramebufferSize() const;
            const std::shared_ptr<Surface> GetSurface() { return _surface; }
            ImVec2 size;
            void OnFramebufferSizeChange();
        private:
            ImGuiWindowFlags _viewPortFlags = 0;
            std::shared_ptr<Framebuffer> _framebuffer;
            std::shared_ptr<Texture> _renderTex;
            std::shared_ptr<Surface> _surface;
            float _aspectRatio = 16.0f / 9.0f;
    };
}