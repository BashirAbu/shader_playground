#ifdef SPG_WINDOWS
#pragma once
#include "core.h"
#include "renderer/renderer_backend.h"
#include <Windows.h>
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
        HDC _hdc;
        HGLRC _openglContext;
    };
}

#endif