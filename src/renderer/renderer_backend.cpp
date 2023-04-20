#include "renderer_backend.h"
#ifdef SPG_WINDOWS
#include "platform/win32/opengl/win32_renderer_backend.h"
#endif
namespace SPG
{
    RendererBackend* RendererBackend::singleton = nullptr;

    RendererBackend* RendererBackend::Create(const RendererBackendSpecs& specs)
    {
        assert(!singleton);
#ifdef SPG_WINDOWS
        singleton = new Win32OpenGLRendererBackend(specs);
#endif
        return singleton;
    }
    
    RendererBackend* RendererBackend::GetSingleton()
    {
        assert(singleton);
        return singleton;
    }


}