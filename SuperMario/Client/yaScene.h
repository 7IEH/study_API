#pragma once
#include "Commoninclude.h"
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{
	using namespace ya::enums;
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Intialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void SetLayer(eLayerType layertype, GameObject* object)
		{
			mLayers[(UINT)layertype].SetObject(object);
		}

	private:
		std::vector<Layer> mLayers;
	};
}

