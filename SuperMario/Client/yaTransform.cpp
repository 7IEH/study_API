#include "yaTransform.h"

namespace ya
{
	Transform::Transform(float x,float y)
		:
		Component(enums::eComponentType::Transform)
		,mPosition(x,y)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Intialize()
	{
	}

	void Transform::Update()
	{
		if (Input::GetKey(eKeyCode::A).state == eKeyState::PRESSED)
		{
			mPosition.x -= Time::DeltaTime() * 300.f;
		}

		if (Input::GetKey(eKeyCode::W).state == eKeyState::PRESSED)
		{
			mPosition.y -= Time::DeltaTime() * 300.f;
		}

		if (Input::GetKey(eKeyCode::S).state == eKeyState::PRESSED)
		{
			mPosition.y += Time::DeltaTime() * 300.f;
		}

		if (Input::GetKey(eKeyCode::D).state == eKeyState::PRESSED)
		{
			mPosition.x += Time::DeltaTime() * 300.f;
		}
	}

	void Transform::Render(HDC hdc)
	{
	}
}