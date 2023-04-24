#pragma once
#include "core.h"
#include "math/spg_maths.h"
namespace SPG
{
    struct TextureSpecs
    {
        int32_t width = 0;
        int32_t height = 0;
        const char* filepath = "";
    };
    class Texture
    {
    public:
        static Texture* Create(const TextureSpecs& specs);
        virtual ~Texture() {}
        virtual void Bind() = 0;
        virtual void Unbind() = 0;
        virtual const Vector2i GetSize() const = 0;
        virtual const uint32_t GetID() const = 0;
    private:
    };
}