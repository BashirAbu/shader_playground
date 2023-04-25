#pragma once
#include "core.h"

namespace SPG
{
    class VertexArray;
    class RendererAPI
    {
    public:
        static RendererAPI* Create();
        static RendererAPI* GetSingleton();
        
        virtual ~RendererAPI() {}
        virtual void SetClearColor(float r, float g, float b, float a) = 0;
        virtual void Clear() = 0;
        virtual void SetViewportSize(int32_t width, int32_t height) = 0;
        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;
    private:
        static RendererAPI* singleton;
    };
}