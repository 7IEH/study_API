#pragma once
#include "Commoninclude.h"

namespace ya
{
	class yaApplication
	{
	public:
		yaApplication();
		~yaApplication();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();
		void SetWindowSize(math::Vector2 other) 
		{ 
			mVwindowSize.x = other.x;
			mVwindowSize.y = other.y;
		}

	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mHmemdc;
		HBITMAP mHbit;

		math::Vector2 mVwindowSize;

		math::Vector2 mPlayerPos;
	};
}

// ���� �����̽��� ����ϴ� ������ ���� �̸��� ������ �������ְ� ������

//namespace yu
//{
//	int a;
//}
//
//namespace i
//{
//	int a;
//}

// ���� �̸������� �ٸ� ������ �ȴ�.