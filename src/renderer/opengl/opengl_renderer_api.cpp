#include "opengl_renderer_api.h"
#include "opengl_headers.h"
#include "opengl_vertex_array.h"
namespace SPG
{
    OpenGLRendererAPI::OpenGLRendererAPI()
    {
        
    }
    
    OpenGLRendererAPI::~OpenGLRendererAPI()
    {
        
    }
    
    void OpenGLRendererAPI::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }
    
    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void OpenGLRendererAPI::SetViewportSize(int32_t width, int32_t height)
    {
        glViewport(0, 0, width, height);
    }
    
    void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
    {
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
    }

}