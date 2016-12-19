#include "texture.h"
#include "../../tools/stb_image.h"
#include "../../helper/res_data.h"
#include <iostream>



Texture::Texture(const std::string& textureId, const std::string& imageId, bool hasAlpha, const std::string& uniformId)
{
	_textureId = textureId;
	GLuint texture;
	glGenTextures(1, &texture);
	_image = texture;
	_uniformId = uniformId;

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, n;
	auto image = stbi_load(ResData::ImageIds[imageId].c_str(), &width, &height, &n, hasAlpha ? STBI_rgb_alpha : STBI_rgb);

	if (!image) std::cerr << ("Loading image '" + ResData::ImageIds[imageId] + "' faild: " + stbi_failure_reason());

	glTexImage2D(GL_TEXTURE_2D, 0, hasAlpha ? GL_RGBA : GL_RGBA, width, height, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind(const Shader* shader, int index) const
{
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, _image);


	if (_uniformId.empty())
		glUniform1i(glGetUniformLocation(shader->GetProgram(), _uniformId.c_str()), index);
	else
		glUniform1i(glGetUniformLocation(shader->GetProgram(), (TEXTURE_UNIFORM_ID + std::to_string(index)).c_str()), index);
}

