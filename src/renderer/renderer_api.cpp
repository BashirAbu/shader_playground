#include "renderer_api.h"
#include "renderer_backend.h"

#include "opengl/opengl_renderer_api.h"


namespace SPG
{
    RendererAPI* RendererAPI::singleton = nullptr;

    RendererAPI* RendererAPI::Create() 
    {
        if(!singleton)
        {
            if(RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL)
            {
                singleton = new OpenGLRendererAPI();
            }
        }
        return singleton;
    }
    
    RendererAPI* RendererAPI::GetSingleton()
    {
        assert(singleton);
        return singleton;
    }
        
}