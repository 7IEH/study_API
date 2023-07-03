#include "yaInput.h"

namespace ya
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::END] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M'
	};

	void Input::Intialize()
	{
		for (size_t i = 0;i < (UINT)eKeyCode::END;i++)
		{
			Key temp = {};
			temp.bPressed = false;
			temp.code = (eKeyCode)i;
			temp.state = eKeyState::NONE;
			mKeys.push_back(temp);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::END; i++)
		{
			// 현재 눌린 상태
			if (GetAsyncKeyState(ASCII[(UINT)mKeys[i].code]) & 0x8000)
			{
				// 전에도 눌렸던 적이있음
				if (mKeys[i].bPressed)
				{
					mKeys[i].state = eKeyState::PRESSED;
				}
				// 전에는 눌렸던 적이 없음
				else
				{
					mKeys[i].bPressed = true;
					mKeys[i].state = eKeyState::DOWN;
				}
			}
			// 현재는 눌려있지 않는 상태
			else
			{
				if (mKeys[i].bPressed)
				{
					mKeys[i].bPressed = false;
					mKeys[i].state = eKeyState::UP;
				}
				else
				{
					mKeys[i].state = eKeyState::NONE;
				}
			}
		}
	}
}
