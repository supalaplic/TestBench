#pragma once
#include <map>
class ResData
{
public:
	static std::map < std::string, std::string > ShaderIds;
	static std::map < std::string, std::string > ImageIds;
	 
	//replace second string with preferences
	static std::map<std::string, std::string> TextureIds;
};
