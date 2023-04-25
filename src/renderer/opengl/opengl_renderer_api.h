#pragma once
#include "core.h"
#include "renderer/renderer_api.h"
namespace SPG
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        OpenGLRendererAPI();
        ~OpenGLRendererAPI();

        void SetClearColor(float r, float g, float b, float a) override;
        void Clear() override;
        void SetViewportSize(int32_t width, int32_t height) override;
        void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
    private:
    };
}