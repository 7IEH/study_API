#include "yaTime.h"

namespace ya
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequnecy = {};
	LARGE_INTEGER Time::mCurFrequnecy = {};
	float Time::mDeltaTime = 0.f;


	void Time::Intialize()
	{
		// CPU 고유 진동수를 가져온다.
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램이 시작됐을때 진동수를 가져온다.
		QueryPerformanceCounter(&mPrevFrequnecy);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequnecy);

		float differenceFrequency
			= static_cast<float>(mCurFrequnecy.QuadPart - mPrevFrequnecy.QuadPart);

		// 델타 타임은 1프레임 사이에 걸리는 시간을 뜻함
		// 지금 카운팅 된 수 - 전 카운팅 된수 빼면 -> 1프레임에 카운팅 된 수가 나옴
		// cpu 고유 진동 수는 말 그대로 1초 몇 카운팅을 뜻함
		// 즉, 1프레임에 초를 구하기 위해서는 1카운팅에 몇초가 걸리지는 지를 알아야 함
		// 1초에 몇 카운팅을 역수로 하면 1카운팅에 몇초를 뜻하게 되고 이를 1프레임에 몇 카운팅에 곱해주면
		// 1프레임에 몇초를 했는지 나오게됨
		mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);

		mPrevFrequnecy.QuadPart = mCurFrequnecy.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float Timecheck = 0.f;

		Timecheck += mDeltaTime;
		if (Timecheck >= 1.0f)
		{
			wchar_t szFloat[50] = {};
			float fps = 1.0f / mDeltaTime;

			swprintf_s(szFloat, 50, L"FPS : %f", fps);
			int strLen = wcsnlen_s(szFloat, 50);

			TextOut(hdc, 10, 10, szFloat, strLen);
			Timecheck = 0.f;
		}
	}
}