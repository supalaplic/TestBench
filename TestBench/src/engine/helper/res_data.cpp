#include "res_data.h"
std::map < std::string, std::string > ResData::ShaderIds{
	{ "basic_shader", "./res/shaders/basic" },
	{ "debug_shader", "./res/shaders/debug" },
	{ "lamp_shader", "./res/shaders/lamp" }
};

std::map < std::string, std::string > ResData::ImageIds{
	{ "awesome_img", "./res/awesomeface.png" },
	{ "container_img", "./res/container.jpg" },
	{ "container2_img", "./res/container2.png"},
};

//replace second string with preferences
std::map<std::string, std::string> ResData::TextureIds{
	{ "cube_tex", "to implement" }
};