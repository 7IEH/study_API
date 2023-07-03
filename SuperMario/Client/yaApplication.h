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
			int vect;
			int group;

			object()
				:
				pos(640.f, 380.f),
				vect(0),
				group(0)
			{

			}
		};

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mHmemdc;
		HBITMAP mHbit;

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