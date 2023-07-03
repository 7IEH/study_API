#pragma once
#include "commoninclude.h"

namespace ya
{
	// Ű�� ����
	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		END,
	};
	// Ű�� ����
	enum class eKeyState
	{
		DOWN,
		UP,
		PRESSED,
		NONE,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode code;
			eKeyState state;
			bool bPressed;
		};

		static void Intialize();
		static void Update();

		// ������ inline
		__forceinline static bool GetKeyDown(eKeyCode code){ return mKeys[(UINT)code].state == eKeyState::DOWN; }
		__forceinline static bool GetKeyUp(eKeyCode code){ return mKeys[(UINT)code].state == eKeyState::UP; }
		__forceinline static Key GetKey(eKeyCode code) { return mKeys[(UINT)code]; }

	private:
		static std::vector<Key> mKeys;
	};
}
