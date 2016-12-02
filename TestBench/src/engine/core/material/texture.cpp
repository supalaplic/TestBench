#include "texture.h"
#include "../../tools/stb_image.h"
#include "../../helper/res_data.h"
#include <iostream>


Texture::Texture(const std::string& id) : _id(id) {}

void Texture::AddImage(const std::string& imageId, bool hasAlpha, const std::string& uniformId)
{
	GLuint texture;
	glGenTextures(1, &texture);
	_images.push_back(texture);
	_uniformIds.push_back(uniformId);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, n;
	auto image = stbi_load(ResData::ImageIds[imageId].c_str(), &width, &height, &n, hasAlpha ? STBI_rgb_alpha : STBI_rgb);
	
	auto faild = stbi_failure_reason();
	if (faild) std::cerr << ("Loading image '" + ResData::ImageIds[imageId] + "' faild: " +  faild);

	glTexImage2D(GL_TEXTURE_2D, 0, hasAlpha ? GL_RGBA : GL_RGBA, width, height, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind(const Shader* shader) const
{
	for (GLuint i = 0; i < _images.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, _images[i]);


		if( i < _uniformIds.size() && !_uniformIds[i].empty())
			glUniform1i(glGetUniformLocation(shader->GetProgram(), _uniformIds[i].c_str()), i);
		else
			glUniform1i(glGetUniformLocation(shader->GetProgram(), (TEXTURE_UNIFORM_ID + std::to_string(i)).c_str()), i);
	}
}
