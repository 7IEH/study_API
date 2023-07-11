#pragma once
#include "yaResource.h"

namespace ya
{
	class Image : public Resource
	{
	public:
		Image();
		virtual ~Image();

		virtual HRESULT Load();

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

		HDC GetHDC() { return mHdc; }

	private:
		HDC mHdc;
		HBITMAP mHbit;

		UINT mWidth;
		UINT mHeight;
	};
}

