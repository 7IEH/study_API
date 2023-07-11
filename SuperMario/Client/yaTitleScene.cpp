#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "EHObject.h"
#include "yaImage.h"
#include "yaResources.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Image* img = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Fighter.bmp");
		Player* player = object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddComponent<SpriteRenderer>();
		player->GetComponent<SpriteRenderer>()->SetImg(img);
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}