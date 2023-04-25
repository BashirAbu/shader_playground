#pragma	once
#include "core.h"
#include <vector>
namespace SPG 
{
	enum class ShaderDataType
	{
		NONE = 0,
		FLOAT,
		FLOAT2,
		FLOAT3,
		FLOAT4,
		INT,
		INT2,
		INT3,
		INT4,
		MAT3,
		MAT4,
		BOOL,
	};
	inline uint32_t GetShaderDataTypeSize(ShaderDataType type) 
	{
		switch (type)
		{
		case ShaderDataType::FLOAT:	return 4;
		case ShaderDataType::FLOAT2:	return 4 * 2;
		case ShaderDataType::FLOAT3:	return 4 * 3;
		case ShaderDataType::FLOAT4:	return 4 * 4;
		case ShaderDataType::INT:		return 4;
		case ShaderDataType::INT2:		return 4 * 2;
		case ShaderDataType::INT3:		return 4 * 3;
		case ShaderDataType::INT4:		return 4 * 4;
		case ShaderDataType::MAT3:		return 4 * 3 * 3;
		case ShaderDataType::MAT4:		return 4 * 4 * 4;
		case ShaderDataType::BOOL:		return 1;
		}
		SPG_LOG_FATAL("This datatype is not supported!");
		return 0;
	}
	struct BufferElement
	{
		BufferElement() {}
		BufferElement(ShaderDataType type, const char* name, bool normalize = false)
			: Name(name), Type(type), Size(GetShaderDataTypeSize(type)), Normalize(normalize){}
		uint32_t GetComponentSize(ShaderDataType type) 
		{
			switch (type)
			{
			case SPG::ShaderDataType::FLOAT: return 1;
				break;
			case SPG::ShaderDataType::FLOAT2: return 2;
				break;
			case SPG::ShaderDataType::FLOAT3: return 3;
				break;
			case SPG::ShaderDataType::FLOAT4: return 4;
				break;
			case SPG::ShaderDataType::INT: return 1;
				break;
			case SPG::ShaderDataType::INT2: return 2;
				break;
			case SPG::ShaderDataType::INT3: return 3;
				break;
			case SPG::ShaderDataType::INT4: return 4;
				break;
			case SPG::ShaderDataType::MAT3: return 3 * 3;
				break;
			case SPG::ShaderDataType::MAT4: return 4 * 4;
				break;
			case SPG::ShaderDataType::BOOL: return 1;
				break;
			}
			SPG_LOG_FATAL("Data type not supported!.");
			return 0;
		}
		const char* Name;
		ShaderDataType Type;
		uint32_t Size = 0;
		uint32_t offset = 0;
		bool Normalize;
	};

	class BufferLayout
	{
	public:
		BufferLayout() {}
		BufferLayout(std::initializer_list<BufferElement> elements) : m_Elements(elements)
		{
			uint32_t offset = 0;
			for (BufferElement& element : m_Elements) 
			{
				m_Stride += element.Size;
				element.offset = offset;
				offset += element.Size;
			}
		}
		const std::vector<BufferElement>& GetElements() const { return m_Elements; }
		uint32_t const GetStride() const 
		{
			return m_Stride; 
		}
	private:
		uint32_t m_Stride = 0;
		std::vector<BufferElement> m_Elements;
	};
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;
		virtual uint32_t GetCount() = 0;
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer 
	{
	public:
		virtual ~IndexBuffer() {}
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual uint32_t GetCount() = 0;
		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}