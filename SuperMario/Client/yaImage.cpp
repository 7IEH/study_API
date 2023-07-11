#include "yaImage.h"
#include "yaApplication.h"

extern ya::yaApplication application;

namespace ya
{
	Image::Image()
		:
		mHdc(nullptr),
		mHbit(nullptr),
		mWidth(0),
		mHeight(0)
	{
	}

	Image::~Image()
	{
	}

	HRESULT Image::Load()
	{
		mHbit = (HBITMAP)LoadImageW(nullptr, GetPath().c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mHbit == nullptr)
		{
			return S_FALSE;
		}

		BITMAP info = {};
		GetObject(mHbit, sizeof(BITMAP), &info);

		mWidth = info.bmWidth;
		mHeight = info.bmHeight;

		mHdc = CreateCompatibleDC(application.GetMainDC());

		HBITMAP defaultBitmap = (HBITMAP)SelectObject(mHdc, mHbit);
		DeleteObject(defaultBitmap);
		
		return S_OK;
	}
}