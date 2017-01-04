#include "texture.h"
#include <iostream>
#include "../../tools/stb_image.h"
#include "../../helper/utils.h"
#include "../resources.h"


Texture::Texture(const std::string& imagePath)
{
	Utils::meta_map map;
	Utils::GetFromMeta(imagePath, map);

	//_id = textureId;
	if (map[RESOURCE_TYPE_KEY] != RESOURCE_TYPE_IMAGE)
	{
		std::cerr << "Meta for '" + imagePath + "' is incompatible: Invalid type." << std::endl;
		return;
	}

	_id = map[RESOURCE_ID_KEY];
	_path = map[RESOURCE_PATH_KEY].c_str();
	_hasAlpha = map[RESOURCE_ALPHA_KEY] == "True";

	LoadData();
}

void Texture::LoadData()
{
	GLuint texture;
	glGenTextures(1, &texture);
	_image = texture;

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, n;
	auto image = stbi_load(_path, &width, &height, &n, _hasAlpha ? STBI_rgb_alpha : STBI_rgb);

	if (!image) std::cerr << "Loading image '" << _path << "' faild: " << stbi_failure_reason();

	glTexImage2D(GL_TEXTURE_2D, 0, _hasAlpha ? GL_RGBA : GL_RGBA, width, height, 0, _hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind(const Shader* shader, int index, const std::string& uniformId) const
{
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, _image);


	if (uniformId.empty())
		glUniform1i(glGetUniformLocation(shader->GetProgram(), uniformId.c_str()), index);
	else
		glUniform1i(glGetUniformLocation(shader->GetProgram(), (TEXTURE_UNIFORM_ID + std::to_string(index)).c_str()), index);
}



