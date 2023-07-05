#pragma once
#include"yaEntity.h"
#include"yaComponent.h"
#include "yaTransform.h"
#include "yaSpriteRenderer.h"
#include"Commoninclude.h"

namespace ya
{
	class GameObject:public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Intialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		template <typename T>
		T* GetComponent()
		{
			T* temp = nullptr;
			for (Component* comp : mComponents)
			{
				temp = dynamic_cast<T*>(comp);
				if (temp != nullptr)
					return temp;
			}
			return temp;
		}

	private:
		std::vector<Component*> mComponents;
	};
}

