#pragma once
#include "yaEntity.h"

namespace ya
{
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		virtual ~Component();

		virtual void Intialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void SetOwner(class GameObject* owner) { mOwner = owner; }
		class GameObject* GetOwner() { return mOwner; }

	private:
		const enums::eComponentType mType;
		class GameObject* mOwner;
	};
}
