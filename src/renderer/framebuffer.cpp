#include "framebuffer.h"
#include "opengl/opengl_framebuffer.h"
#include "renderer_backend.h"
namespace SPG
{
    Framebuffer* Framebuffer::Create(const FramebufferSpecs& specs)
    {
        Framebuffer* Framebuffer = nullptr;
        if(RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL)
        {
            Framebuffer = new OpenGLFramebuffer(specs);
        }
        return Framebuffer;
    }

    
} // namespace SPG
