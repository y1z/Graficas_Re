#pragma once
#include "Usable_Windows.h"
#include "DirectXHeader.h"
#include "CDevice.h"
#include <cinttypes>

#include "Utility/ErrorHandlingGrafics.h"

class CSwapChian
{
public:
	CSwapChian();
	~CSwapChian();
public:// functions

	bool GetBuffer(int32_t BufferIndex,void *Buffer);
	bool Present(int32_t Syc = 0 , int32_t PresentOpction = 0);

	void ResizeBuffer(int width, int height, HWND g_hWnd);
	void ResizeTarget(int width, int height);

	/*! This is just for creating the SwapChian*/
	IDXGISwapChain** GetSwapChianRef();

public:// variable
	IDXGISwapChain* mptr_SwapChian = nullptr;
};

