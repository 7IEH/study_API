#include "yaApplication.h"

namespace ya
{
	yaApplication::yaApplication()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mHbit(nullptr)
		, mHmemdc(nullptr)
		, mVwindowSize(0.f, 0.f)
		, mScene{}
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

		RECT rect = { 0,0,1280,720 };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(hwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(hwnd,true);
		mHmemdc = (HDC)CreateCompatibleDC(mHdc);
		mHbit = (HBITMAP)CreateCompatibleBitmap(mHdc, 1280, 720);

		HBITMAP hOldBit = (HBITMAP)SelectObject(mHmemdc, mHbit);
		DeleteObject(hOldBit);

		Time::Intialize();
		Input::Intialize();
		Scene EnterScene;
		GameObject* mPlayer = new GameObject;
		EnterScene.SetLayer(enums::eLayerType::Player, mPlayer);
		mScene.push_back(EnterScene);
;	}

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
		for (size_t i = 0; i < mScene.size(); i++)
		{
			mScene[i].Update();
		}
	}

	void yaApplication::Render()
	{
		// rewrite
		Rectangle(mHmemdc, -1, -1, mVwindowSize.x+1, mVwindowSize.y+1);
		Time::Render(mHmemdc);
		for (size_t i = 0; i < mScene.size(); i++)
		{
			mScene[i].Render(mHmemdc);
		}
		BitBlt(mHdc, 0, 0, 1280, 720, mHmemdc, 0, 0, SRCCOPY);
	}
}