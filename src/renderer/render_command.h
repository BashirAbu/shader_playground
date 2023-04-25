#pragma once
#include "core.h"

namespace SPG
{
    class VertexArray;
    class RenderCommand
    {
    public:
        static void SetClearColor(float r, float g, float b, float a);
        static void Clear();
        static void SetViewportSize(int32_t width, int32_t height);
        static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
    };
}