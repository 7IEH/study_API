#pragma once
#include"yaComponent.h"
#include"yaInput.h"
#include"yaTime.h"
namespace ya
{
	class Transform :public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetPos(math::Vector2& pos) { mPosition = pos; }
		math::Vector2 GetPos() { return mPosition; }

	private:
		math::Vector2 mPosition;
	};
}

