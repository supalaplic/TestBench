#include <iostream>
#include "../resources.h"

Material::Material(const std::string& id, const std::string& shaderId, const std::string& textureId)
{
	_id = id;

	//implement default shader
	if (shaderId != "")
		_shader = Resources::GetShader(shaderId);
	else
		std::cerr << "Implement default shader" << std::endl;
	
	_texture = nullptr;
	if (!textureId.empty())
		_texture = Resources::GetTexture(textureId);
}

//remove this when batching is implemented
void Material::Bind()
{
	_shader->Bind();

	if (_texture != nullptr)
		_texture->Bind(_shader);
}


