#pragma once
#include "Commoninclude.h"
#include "yaEntity.h"

namespace ya
{
	class Resource : public Entity
	{
	public:
		virtual HRESULT Load() = 0;

		std::wstring GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		std::wstring mPath;
	};
}

