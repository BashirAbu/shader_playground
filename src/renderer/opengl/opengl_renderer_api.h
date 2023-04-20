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

        void SetClearColor(float r, float g, float b, float a);
        void Clear();
        virtual void SetViewportSize(int32_t width, int32_t height);
    private:
    };
}