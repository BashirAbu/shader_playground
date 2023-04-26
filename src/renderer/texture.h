#pragma once
#include "core.h"
#include "math/spg_maths.h"
namespace SPG
{
    enum class TextureFormat
    {
        RGB = 0,
        RGBA
    };
    struct TextureSpecs
    {
        int32_t width = 0;
        int32_t height = 0;
        TextureFormat format = TextureFormat::RGB;
        const char* filepath = "";
        void* data = nullptr;
    };
    class Texture
    {
    public:
        static Texture* Create(const TextureSpecs& specs);
        virtual ~Texture() {}
        virtual void Bind() = 0;
        virtual void Unbind() = 0;
        virtual void UpdateData(void* data, int32_t width, int32_t height) = 0;
        virtual void Copy(uint32_t id, int32_t width, int32_t height) = 0;
        virtual const void* GetTextureData() = 0;
        virtual const Vector2i GetSize() const = 0;
        virtual const uint32_t GetID() const = 0;
    private:
    };
}