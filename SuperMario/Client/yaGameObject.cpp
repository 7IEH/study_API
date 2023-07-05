#include "yaGameObject.h"

namespace ya
{
	GameObject::GameObject()
	{
		mComponents.push_back(new Transform(0.f,0.f));
		mComponents.push_back(new SpriteRenderer());

		for (Component* comp : mComponents)
		{
			comp->SetOwner(this);
		}
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Intialize()
	{
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
}