#include "yaSpriteRenderer.h"

namespace ya
{
	SpriteRenderer::SpriteRenderer()
		:
		Component(enums::eComponentType::SpriteRenderer)
		,mImg(nullptr)
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


		TransparentBlt(hdc, pos.x, pos.y, mImg->GetWidth(), mImg->GetHeight(), mImg->GetHDC(), 0, 0, mImg->GetWidth(), mImg->GetHeight(), RGB(255, 0, 255));
	}
}