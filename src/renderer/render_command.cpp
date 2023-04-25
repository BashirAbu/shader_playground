#include "render_command.h"
#include "renderer_api.h"
namespace SPG
{
    void RenderCommand::SetClearColor(float r, float g, float b, float a)
    {
        RendererAPI::GetSingleton()->SetClearColor(r, g, b, a);
    }
    
    void RenderCommand::Clear()
    {
        RendererAPI::GetSingleton()->Clear();
        
    }
    
    void RenderCommand::SetViewportSize(int32_t width, int32_t height)
    {
        RendererAPI::GetSingleton()->SetViewportSize(width, height);
    }
    
    void RenderCommand::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
    {
        RendererAPI::GetSingleton()->DrawIndexed(vertexArray);
    }


}