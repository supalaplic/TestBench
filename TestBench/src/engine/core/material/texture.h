#pragma once
#include <vector>
#include "Shader.h"

#define TEXTURE_UNIFORM_ID "Texture"
class Texture
{
private:
	std::string _id;
	const char* _path;
	GLboolean _hasAlpha;
	GLuint _image;

public:

	Texture(const std::string& imagePath);
	virtual ~Texture() {}
	//uniformId is used to identify the sampler form the used shader
	//if no uniformId is provided Texture + (index in material) will be used
	void Bind(const Shader* shader, int index, const std::string& uniformId = "") const;
private:
	Texture(const Texture&) {}
	void operator=(const Texture*) const{}

	void LoadData();
};

