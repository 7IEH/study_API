#pragma once
#include "Commoninclude.h"

namespace ya
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(std::wstring name) { mName = name; }
		std::wstring& GetName() { return mName; }
	private:
		std::wstring mName;
	};
}

