#pragma once

#include <string>
#include <unordered_map>
#include <any>

namespace WpfApplication2
{
	class JsonParser
	{
	private:
		JavaScriptSerializer *serializer;
	public:
		virtual ~JsonParser()
		{
			delete serializer;
		}

		JsonParser();
		std::unordered_map<std::wstring, std::any> Deserialize(const std::wstring &json);
	};

}
