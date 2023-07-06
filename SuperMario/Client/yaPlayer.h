#pragma once
#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	class Player : public GameObject
	{
	public:
		Player();
		virtual ~Player();

		virtual void Intialize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
	};
}
