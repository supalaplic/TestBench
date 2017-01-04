#include "utils.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Utils::meta_map Utils::GetFromMeta(const std::string& metaPath, meta_map& map)
{
	auto path = metaPath + ".meta";
	std::ifstream metaFile;
	std::string line;

	metaFile.open(path);
	if(metaFile.fail())
		std::cerr << "Failed to open meta file: '" << path.c_str() << "'" << std::endl;


	while (std::getline(metaFile, line))
	{
		std::vector<std::string> data;
		Split(line, ':', data);
		map[data[0]] = data[1];
	}

	metaFile.close();
	return map;
}

void Utils::Split(const std::string& s, char delim, std::vector<std::string>& elems)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
