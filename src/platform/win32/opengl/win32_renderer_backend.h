#ifdef SPG_WINDOWS
#pragma once
#include "core.h"
#include "renderer/renderer_backend.h"
namespace SPG
{

    class Win32OpenGLRendererBackend :  public RendererBackend
    {
    public:
        Win32OpenGLRendererBackend(const RendererBackendSpecs& specs);
        ~Win32OpenGLRendererBackend();
        void LoadOpenGLExtensions();
        virtual RendererBackendAPI GetAPI();
    private:
        RendererBackendSpecs _specs;
    };
}

#endif