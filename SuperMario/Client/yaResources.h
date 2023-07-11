#pragma once
#include "Commoninclude.h"
#include "yaResource.h"

namespace ya
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& name)
		{
			std::map<std::wstring, Resource*>::iterator iter = mResources.find(name);
			if (iter == mResources.end())
			{
				return nullptr;
			}

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& name, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(name);
			if (resource != nullptr)
			{
				return resource;
			}

			resource = new T();
			resource->SetPath(path);
			resource->SetName(name);
			if (FAILED(resource->Load()))
			{
				MessageBox(nullptr, L"Resource Load Failed!", L"Error", MB_OK);
				delete resource;
				return nullptr;
			}
			mResources.insert(std::make_pair(name,resource));
			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}

