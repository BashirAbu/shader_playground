#pragma once
#include "core.h"

namespace SPG
{
    enum class RendererBackendAPI
    {
        OPENGL = 0
    };
    struct RendererBackendSpecs
    {
        RendererBackendAPI api = RendererBackendAPI::OPENGL;
        void* internalWindowHandle;
    };
    class RendererBackend
    {
    public:
        virtual ~RendererBackend(){}
        static RendererBackend* Create(const RendererBackendSpecs& specs);
        static RendererBackend* GetSingleton();
        virtual RendererBackendAPI GetAPI() = 0;
		virtual void SetVsync(bool on) = 0;
    private:
        static RendererBackend* singleton;
    };
}