#include <iostream>
#include "../resources.h"

Material::Material(const std::string& materialId, const std::string& shader)
{
	_materialId = materialId;
	_shader = Resources::GetShader(shader);
}

void Material::AddTexture(const std::string& textureId)
{
	_textures.push_back(Resources::GetTexture(textureId));
}

void Material::AddTexture(Texture* textureId)
{
	_textures.push_back(textureId);
}

//remove this when batching is implemented
void Material::Bind()
{
	_shader->Bind();

	for (size_t i = 0; i < _textures.size(); i++)
	{
		_textures[i]->Bind(_shader, i);
	}
}


