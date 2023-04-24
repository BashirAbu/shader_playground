#include "texture.h"
#include "opengl/opengl_texture.h"
#include "renderer/renderer_backend.h"
namespace SPG
{
    Texture* Texture::Create(const TextureSpecs& specs)
    {
        Texture* texture = nullptr;
        if(RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL)
        {
            texture = new OpenGLTexture(specs);
        }
        return texture;
    }
} // namespace SPG
