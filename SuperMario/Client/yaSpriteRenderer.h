#pragma once
#include "yaComponent.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class SpriteRenderer :public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Intialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		Image* GetImg() { return mImg; }
		void SetImg(Image* img) { mImg = img; }

	private:
		Image* mImg;
	};
}

