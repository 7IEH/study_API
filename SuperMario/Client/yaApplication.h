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

// 네임 스페이스를 사용하는 이유는 같은 이름의 변수를 생성해주고 싶을때

//namespace yu
//{
//	int a;
//}
//
//namespace i
//{
//	int a;
//}

// 같은 이름이지만 다른 변수가 된다.