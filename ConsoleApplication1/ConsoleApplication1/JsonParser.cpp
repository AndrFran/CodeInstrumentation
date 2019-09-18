#include "JsonParser.h"

namespace WpfApplication2
{

	JsonParser::JsonParser()
	{
		serializer = new JavaScriptSerializer();
	}

	std::unordered_map<std::wstring, std::any> JsonParser::Deserialize(const std::wstring &json)
	{
		serializer->Deserialize<std::unordered_map<std::wstring, std::any>>(json);
		std::unordered_map<std::wstring, std::any> ParsedFunction = serializer->Deserialize<std::unordered_map<std::wstring, std::any>>(json);
		return ParsedFunction;
	}
}
