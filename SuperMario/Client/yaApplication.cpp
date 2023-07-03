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
		, mVwindowSize(0.f, 0.f)
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
		mVwindowSize=math::Vector2(1280.f, 760.f);

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

		static int count = 0;
		if (TimeCheck >= 2.f && count<=5)
		{
			object temp;
			count++;
			temp.dir.x = vect[temp.group][flag][0];
			temp.dir.y = vect[temp.group][flag++][1];
			mObject.push_back(temp);
			TimeCheck = 0.f;
			if (flag == 3)
				flag = 0;
		}

		
		
		srand((UINT)time(NULL));
		int Irand = 0;
		for (size_t i = 0; i < mObject.size(); i++)
		{
			/*for (size_t j = 0; j < mObject.size(); j++)
			{
				if (j == i)
					continue;

				if (mObject[j].pos.x <= mObject[i].pos.x &&
					mObject[j].pos.x + 102.f >= mObject[i].pos.x &&
					mObject[j].pos.y <= mObject[i].pos.y &&
					mObject[j].pos.y + 102.f >= mObject[i].pos.y)
				{
					mObject[i].dir.x *= -1.f;
					mObject[i].dir.y *= -1.f;
					mObject[j].dir.x *= -1.f;
					mObject[j].dir.y *= -1.f;
					if (mObject[i].group = 7)
					{
						mObject[i].group = 1;
					}
					else
					{
						mObject[i].group++;
					}

					if (mObject[j].group = 7)
					{
						mObject[j].group = 1;
					}
					else
					{
						mObject[j].group++;
					}
				}
			}*/
			if (mObject[i].pos.x >= mVwindowSize.x-100.f && mObject[i].pos.y <= 0.f)
			{
				mObject[i].group = 2;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}
			else if (mObject[i].pos.x <= 0.f && mObject[i].pos.y <= 0.f)
			{
				mObject[i].group = 0;
			}
			else if (mObject[i].pos.y >= mVwindowSize.y-100.f && mObject[i].pos.x >= mVwindowSize.x - 100.f)
			{
				mObject[i].group = 4;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}
			else if (mObject[i].pos.y >= mVwindowSize.y - 100.f && mObject[i].pos.x <= 0.f)
			{
				mObject[i].group = 6;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}
			else if (mObject[i].pos.x >= mVwindowSize.x - 100.f)
			{
				mObject[i].group = 3;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}
			else if (mObject[i].pos.x <= 0.f)
			{
				mObject[i].group = 7;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}
			else if (mObject[i].pos.y <= 0.f)
			{
				mObject[i].group = 1;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}
			else if (mObject[i].pos.y >= mVwindowSize.y - 100.f)
			{
				mObject[i].group = 5;
				Irand = rand() % 3;
				mObject[i].dir.x = vect[mObject[i].group][Irand][0];
				mObject[i].dir.y = vect[mObject[i].group][Irand][1];
			}

			mObject[i].pos.x += mObject[i].dir.x * 500.f * Time::DeltaTime();
			mObject[i].pos.y += mObject[i].dir.y * 500.f * Time::DeltaTime();
		}	
}

void yaApplication::Render()
{
	// rewrite
	// Rectangle(mHdc, 0, 0, 1280, 760);
	Time::Render(mHmemdc);
	Rectangle(mHdc, mPlayerPos.x, mPlayerPos.y, mPlayerPos.x + 100.f, mPlayerPos.y + 100.f);

	for (size_t i = 0; i < mObject.size(); i++)
	{
		Ellipse(mHdc, mObject[i].pos.x, mObject[i].pos.y, mObject[i].pos.x + 100, mObject[i].pos.y + 100);
	}

	//BitBlt(mHdc, 0, 0, 1280, 760, mHmemdc, 0, 0, SRCCOPY);
}

}
