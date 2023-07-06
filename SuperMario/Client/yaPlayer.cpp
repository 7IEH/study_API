#include "yaPlayer.h"

namespace ya
{
	Player::Player()
	{
	}

	Player::~Player()
	{
	}

	void Player::Intialize()
	{
	}

	void Player::Update()
	{
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::A).state == eKeyState::PRESSED)
		{
			pos.x -= Time::DeltaTime() * 300.f;
		}

		if (Input::GetKey(eKeyCode::W).state == eKeyState::PRESSED)
		{
			pos.y -= Time::DeltaTime() * 300.f;
		}

		if (Input::GetKey(eKeyCode::S).state == eKeyState::PRESSED)
		{
			pos.y += Time::DeltaTime() * 300.f;
		}

		if (Input::GetKey(eKeyCode::D).state == eKeyState::PRESSED)
		{
			pos.x += Time::DeltaTime() * 300.f;
		}

		tr->SetPos(pos);
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}