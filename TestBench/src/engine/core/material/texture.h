#pragma once
#include <vector>
#include "Shader.h"

#define TEXTURE_UNIFORM_ID "Texture"
class Texture
{
private:
	std::string _id;
	std::vector<GLuint> _images;
	std::vector<std::string> _uniformIds;


public:
	Texture(const std::string& id);
	virtual ~Texture() {}
	void Bind(const Shader* shader) const;
	//uniform id is the if of the imdeId texture in the shaders
	//if no uniformId is given, Texture + image_index will be used
	void AddImage(const std::string& imagerId, bool hasAlpha = false, const std::string& uniformId = "");
private:
	Texture(const Texture&) {}
	void operator=(const Texture*) const{}

};

