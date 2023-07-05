#pragma once
#include "Commoninclude.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaScene.h"
#include "yaGameObject.h"

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

		std::vector<Scene> mScene;
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