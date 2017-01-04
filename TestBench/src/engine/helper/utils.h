#pragma once
#include <map>
#include <vector>

class Utils
{
public:
	Utils() {}
	~Utils() {}

	typedef std::map<std::string, std::string> meta_map;
	static meta_map GetFromMeta(const std::string& metaPath, meta_map& map);

	//does not skip empt tokens
	static void Split(const std::string &s, char delim, std::vector<std::string> &elems);

private:
	Utils(const Utils&) {}
	void operator=(const Utils&) {}
};

