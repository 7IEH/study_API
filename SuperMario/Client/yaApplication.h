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