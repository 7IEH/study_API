#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>

#include "framework.h"
#include "yaMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace ya::enums
{
	enum class eLayerType
	{
		Background,
		Player,
		Monster,
		Effect,
		UI,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		End,
	};
}