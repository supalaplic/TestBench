#pragma once
#include <vector>
#include "Shader.h"


class Texture
{
private:
	std::string _id;
	std::vector<GLuint> _images;


public:
	Texture(std::string id);
	virtual ~Texture() {}
	void Bind(const Shader* shader) const;
	void AddImage(const std::string& imagerId, bool hasAlpha = false);
private:
	Texture(const Texture&) {}
	void operator=(const Texture*) const{}

};

