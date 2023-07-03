#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include<time.h>

namespace ya
{
	yaApplication::yaApplication()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mHbit(nullptr)
		, mHmemdc(nullptr)
		, mPlayerPos(10.f, 10.f)
	{
	}

	yaApplication::~yaApplication()
	{
		ReleaseDC(mHwnd, mHdc);
		DeleteDC(mHmemdc);
	}

	void yaApplication::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mHmemdc = (HDC)CreateCompatibleDC(mHdc);
		mHbit = (HBITMAP)CreateCompatibleBitmap(mHdc, 1280, 780);

		HBITMAP hOldBit = (HBITMAP)SelectObject(mHmemdc, mHbit);
		DeleteObject(hOldBit);

		Input::Intialize();
		Time::Intialize();
	}

	void yaApplication::Run()
	{
		// 1frame ->  한장 한장을 말함
		Update();
		Render();
	}

	void yaApplication::Update()
	{
		Time::Update();
		Input::Update();
		if (Input::GetKey(eKeyCode::A).state == eKeyState::PRESSED)
		{
			mPlayerPos.x -= 300.f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W).state == eKeyState::PRESSED)
		{
			mPlayerPos.y -= 300.f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S).state == eKeyState::PRESSED)
		{
			mPlayerPos.y += 300.f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D).state == eKeyState::PRESSED)
		{
			mPlayerPos.x += 300.f * Time::DeltaTime();
		}

		static float TimeCheck = 0.f;
		TimeCheck += Time::DeltaTime();
		static int flag = 0;

		if (TimeCheck >= 2.f)
		{
			object temp;
			temp.vect = flag++;
			mObject.push_back(temp);
			TimeCheck = 0.f;
			if (flag == 3)
				flag = 0;
		}

		int vect[8][5][2] =
		{
			{
				0,1,
				1,1,
				1,0
			},
			{
				-1,1,
				0,1,
				1,1
			},
			{
				-1,0,
				-1,1,
				0,1
			},
			{
				-1,-1,
				-1,0,
				-1,1
			},
			{
				0,-1,
				-1,-1,
				-1,0
			},
			{
				1,-1,
				0,-1,
				-1,-1
			},
			{
				1,0,
				1,-1,
				0,-1
			},
			{
				1,1,
				1,0,
				1,-1
			}
		};
		
		srand((UINT)time(NULL));
		for (size_t i = 0; i < mObject.size(); i++)
		{
			if (mObject[i].pos.x >= 1180.f && mObject[i].pos.y <= 0.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 2;
			}
			else if (mObject[i].pos.x <= 0.f && mObject[i].pos.y <= 0.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 0;
			}
			else if (mObject[i].pos.y >= 660.f && mObject[i].pos.x >= 1180.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 4;
			}
			else if (mObject[i].pos.y >= 660.f && mObject[i].pos.x <= 0.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 6;
			}
			else if (mObject[i].pos.x >= 1180.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 3;
			}
			else if (mObject[i].pos.x <= 0.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 7;
			}
			else if (mObject[i].pos.y <= 0.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 1;
			}
			else if (mObject[i].pos.y >= 660.f)
			{
				mObject[i].vect = rand() % 3;
				mObject[i].group = 5;
			}
			mObject[i].pos.x += vect[mObject[i].group][mObject[i].vect][0] * 500.f * Time::DeltaTime();
			mObject[i].pos.y += vect[mObject[i].group][mObject[i].vect][1] * 500.f * Time::DeltaTime();
		}	
}

void yaApplication::Render()
{
	// rewrite
	Rectangle(mHmemdc, 0, 0, 1280, 760);
	// Time::Render(mHmemdc);
	Rectangle(mHmemdc, mPlayerPos.x, mPlayerPos.y, mPlayerPos.x + 100.f, mPlayerPos.y + 100.f);

	for (size_t i = 0; i < mObject.size(); i++)
	{
		Ellipse(mHmemdc, mObject[i].pos.x, mObject[i].pos.y, mObject[i].pos.x + 100, mObject[i].pos.y + 100);
	}

	BitBlt(mHdc, 0, 0, 1280, 760, mHmemdc, 0, 0, SRCCOPY);
}

}
