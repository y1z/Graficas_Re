#pragma once
#include "Usable_Windows.h"
#include "DirectXHeader.h"
#include <cinttypes>
namespace Templates {

	namespace {

		class CBuffer
		{
		public:
			CBuffer();
			~CBuffer();
		public:// functions 

			template<class T>
			void IntiVertexBuffer(const T * DataStruct, uint64_t TotalElements, uint32_t OffSet);

			template<class T>
			void InitIndexBuffer(const T * DataStruct, uint64_t TotalElements, uint32_t OffSet);

			template<class T>
			void InitConstBuffer(const T &DataStruct, uint32_t Offset);

			UINT GetStride();
			UINT GetOffset();

		#ifdef USING_DIRECTX
			ID3D11Buffer* GetBuffer();
			ID3D11Buffer** GetBufferRef();
			D3D11_BUFFER_DESC GetDesc();
			D3D11_BUFFER_DESC& GetDescRef();
			D3D11_SUBRESOURCE_DATA GetData();
			D3D11_SUBRESOURCE_DATA& GetDataRef();
		#endif // USING_DIRECTX

			uint64_t GetElementCount();
			// 

			D3D11_BUFFER_DESC m_Discriptor;
			D3D11_SUBRESOURCE_DATA m_Data;

		private://variables
			ID3D11Buffer *mptr_Buffer = nullptr;

			uint32_t m_Stride = 0;
			uint32_t m_Offset = 0;
			uint64_t m_CountElemets = 0;
		};


		CBuffer::CBuffer()
		{
			memset(&m_Discriptor, 0, sizeof(m_Discriptor));
			memset(&m_Data, 0, sizeof(m_Data));
		}


		CBuffer::~CBuffer()
		{
			if (mptr_Buffer != nullptr) { mptr_Buffer->Release(); }
		}

		template<class T>/*! This function set up the buffer to later become a Vertex buffer*/
		inline void CBuffer::IntiVertexBuffer(const T * DataStruct, uint64_t TotalElements, uint32_t OffSet)
		{
		#if defined(USING_DIRECTX)
			m_Discriptor.Usage = D3D11_USAGE_DEFAULT;
			m_Discriptor.BindFlags = D3D11_BIND_VERTEX_BUFFER;

			m_Discriptor.ByteWidth = sizeof(*DataStruct) * TotalElements;
			m_Discriptor.CPUAccessFlags = 0;

			m_CountElemets = TotalElements;

			m_Stride = sizeof(*DataStruct);
			m_Offset = OffSet;

			m_Data.pSysMem = DataStruct;
		#elif
		#endif
		}

		template<class T>/*! This function set up the buffer to later become a index buffer*/
		inline void CBuffer::InitIndexBuffer(const T * DataStruct, uint64_t TotalElements, uint32_t OffSet)
		{
		#if defined(USING_DIRECTX)
			m_Discriptor.Usage = D3D11_USAGE_DEFAULT;
			m_Discriptor.BindFlags = D3D11_BIND_INDEX_BUFFER;

			m_Discriptor.ByteWidth = sizeof(*DataStruct) * TotalElements;
			m_Discriptor.CPUAccessFlags = 0;

			m_CountElemets = TotalElements;

			m_Stride = sizeof(*DataStruct);
			m_Offset = OffSet;

			m_Data.pSysMem = DataStruct;
		#elif
		#endif
		}

		template<class T>/*! This function set up the buffer to later become a constant buffer.*/
		inline void CBuffer::InitConstBuffer(const T &DataStruct, uint32_t Offset)
		{
		#if defined(USING_DIRECTX)
			m_Discriptor.Usage = D3D11_USAGE_DEFAULT;
			m_Discriptor.ByteWidth = sizeof(T);

			m_Stride = sizeof(T);
			m_Offset = Offset;

			m_Discriptor.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			m_Discriptor.CPUAccessFlags = 0;

		#	elif
		#endif
		}

		ID3D11Buffer * CBuffer::GetBuffer()
		{
			return mptr_Buffer;
		}

		ID3D11Buffer ** CBuffer::GetBufferRef()
		{
			return &mptr_Buffer;
		}

		inline D3D11_BUFFER_DESC CBuffer::GetDesc()
		{
			return m_Discriptor;
		}

		inline D3D11_BUFFER_DESC & CBuffer::GetDescRef()
		{
			return m_Discriptor;
		}

		inline D3D11_SUBRESOURCE_DATA CBuffer::GetData()
		{
			return m_Data;
		}

		inline D3D11_SUBRESOURCE_DATA & CBuffer::GetDataRef()
		{
			return m_Data;
		}

		inline uint64_t CBuffer::GetElementCount()
		{
			return m_CountElemets;
		}

		inline uint32_t CBuffer::GetStride()
		{
			return m_Stride;
		}

		inline uint32_t CBuffer::GetOffset()
		{
			return m_Offset;
		}
	};
};