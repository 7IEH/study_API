#pragma once
#include "Commoninclude.h"
#include "yaEntity.h"
#include "yaGameObject.h"

namespace ya
{
	class Layer:public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Intialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void SetObject(GameObject* obj)
		{
			mGameObjects.push_back(obj);
		}

	private:
		std::vector<GameObject*> mGameObjects;
	};
}