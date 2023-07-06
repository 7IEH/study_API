#pragma once
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaSceneMgr.h"


namespace ya::object
{
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type)
	{
		T* obj = new T();
		Scene* CurScene = SceneMgr::GetCurScene();
		CurScene->AddLayer(type, obj);

		return obj;
	}
}
