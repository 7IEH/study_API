#pragma once
#include "Commoninclude.h"
#include "yaScene.h"


namespace ya
{
	class SceneMgr
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		template <typename T>
		static T* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mScenes.insert(std::make_pair(name, scene));
			mActiveScene = scene;
			scene->Initialize();

			return scene;
		}

		static Scene* GetCurScene() { return mActiveScene; }
		static Scene* LoadScene(const std::wstring& name);
		static void ChangeScene(const std::wstring& name) { LoadScene(name); }

	private:
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
	};
}

