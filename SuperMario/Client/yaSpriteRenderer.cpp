#include "yaSpriteRenderer.h"

namespace ya
{
	SpriteRenderer::SpriteRenderer()
		:
		Component(enums::eComponentType::SpriteRenderer)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Intialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* tf = GetOwner()->GetComponent<Transform>();
		ya::math::Vector2 pos = tf->GetPos();
		Rectangle(hdc, 100+pos.x, 100+ pos.y, 200+ pos.x, 200+ pos.y);
	}
}