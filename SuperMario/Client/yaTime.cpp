#include "yaTime.h"

namespace ya
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequnecy = {};
	LARGE_INTEGER Time::mCurFrequnecy = {};
	float Time::mDeltaTime = 0.f;


	void Time::Intialize()
	{
		// CPU ���� �������� �����´�.
		QueryPerformanceFrequency(&mCpuFrequency);

		// ���α׷��� ���۵����� �������� �����´�.
		QueryPerformanceCounter(&mPrevFrequnecy);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequnecy);

		float differenceFrequency
			= static_cast<float>(mCurFrequnecy.QuadPart - mPrevFrequnecy.QuadPart);

		// ��Ÿ Ÿ���� 1������ ���̿� �ɸ��� �ð��� ����
		// ���� ī���� �� �� - �� ī���� �ȼ� ���� -> 1�����ӿ� ī���� �� ���� ����
		// cpu ���� ���� ���� �� �״�� 1�� �� ī������ ����
		// ��, 1�����ӿ� �ʸ� ���ϱ� ���ؼ��� 1ī���ÿ� ���ʰ� �ɸ����� ���� �˾ƾ� ��
		// 1�ʿ� �� ī������ ������ �ϸ� 1ī���ÿ� ���ʸ� ���ϰ� �ǰ� �̸� 1�����ӿ� �� ī���ÿ� �����ָ�
		// 1�����ӿ� ���ʸ� �ߴ��� �����Ե�
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