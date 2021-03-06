#pragma once
#include "Usable_Windows.h"
#include "DirectXHeader.h"
#include "Structs.h"
#include <vector>
#include "CBuffer.h"

class CMesh
{
public:
	CMesh();

#ifdef USING_DIRECTX
	CMesh(std::vector<unsigned short> Indeces, std::vector<SimpleVertex> Vertexes);
#endif // USING_DIRECTX

	~CMesh();

public:
	Templates::CBuffer &GetIndexBuffer();
	Templates::CBuffer &GetVertexBuffer();

	Templates::CBuffer mptr_IndexBuffer;
	Templates::CBuffer mptr_VertexBuffer;

private:


};

