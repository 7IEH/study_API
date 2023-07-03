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
			// ���� ���� ����
			if (GetAsyncKeyState(ASCII[(UINT)mKeys[i].code]) & 0x8000)
			{
				// ������ ���ȴ� ��������
				if (mKeys[i].bPressed)
				{
					mKeys[i].state = eKeyState::PRESSED;
				}
				// ������ ���ȴ� ���� ����
				else
				{
					mKeys[i].bPressed = true;
					mKeys[i].state = eKeyState::DOWN;
				}
			}
			// ����� �������� �ʴ� ����
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
