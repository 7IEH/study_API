#include "yaLayer.h"

namespace ya
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
	}
	void Layer::Intialize()
	{
	}
	void Layer::Update()
	{
		for (GameObject* Obj : mGameObjects)
		{
			Obj->Update();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* Obj : mGameObjects)
		{
			Obj->Render(hdc);
		}
	}
}
