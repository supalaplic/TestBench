#pragma once
#include <vector>
#include "Shader.h"

#define TEXTURE_UNIFORM_ID "Texture"
class Texture
{
private:
	std::string _textureId;
	GLuint _image;
	std::string _uniformId;


public:
	//uniformId is used to identify the sampler form the used shader
	//if no uniformId is provided Texture + (index in material) will be used
	Texture(const std::string& textureId, const std::string& imageId, bool hasAlpha = false, const std::string& uniformId = "");
	virtual ~Texture() {}
	void Bind(const Shader* shader, int index = 0) const;
private:
	Texture(const Texture&) {}
	void operator=(const Texture*) const{}

};

