#pragma once
#include "Commoninclude.h"

namespace ya
{
	class Time
	{
	public:
		static void Intialize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static float DeltaTime() { return mDeltaTime; }

	private:
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequnecy;
		static LARGE_INTEGER mCurFrequnecy;
		static float mDeltaTime;
	};
}

