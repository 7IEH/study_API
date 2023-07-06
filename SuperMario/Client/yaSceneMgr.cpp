#include "yaSceneMgr.h"
#include "yaTitleScene.h"

namespace ya
{
	std::map<std::wstring, Scene*> SceneMgr::mScenes = {};
	Scene* SceneMgr::mActiveScene = nullptr;

	void SceneMgr::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");

		LoadScene(L"TitleScene");
	}

	void SceneMgr::Update()
	{
		mActiveScene->Update();
	}

	void SceneMgr::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneMgr::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end())
		{
			return nullptr;
		}

		mActiveScene = iter->second;
		return iter->second;
	}

}