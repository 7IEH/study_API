#include "yaComponent.h"
namespace ya
{
	Component::Component(enums::eComponentType type)
		:
		mType(type)
		,mOwner(nullptr)
	{
	}
	Component::~Component()
	{
	}
	void Component::Intialize()
	{
	}
	void Component::Update()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}