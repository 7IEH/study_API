#pragma once
#include "Commoninclude.h"

namespace ya
{
	class yaApplication
	{
	public:
		yaApplication();
		~yaApplication();

		struct object
		{
			ya::math::Vector2 pos;
			ya::math::Vector2 dir;
			int group;

			object()
				:
				pos(640.f, 380.f),
				dir(0.f,0.f),
				group(0)
			{

			}
		};

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
		std::vector<object> mObject;
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