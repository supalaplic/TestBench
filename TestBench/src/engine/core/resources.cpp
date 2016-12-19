#include "resources.h"
#include "../helper/res_data.h"

std::map<std::string, std::unique_ptr<Shader>> Resources::_shaders;
std::map<std::string, std::unique_ptr<Texture>> Resources::_textures;
std::map<std::string, std::unique_ptr<Material>> Resources::_materials;
std::map<std::string, std::unique_ptr<Mesh>> Resources::_meshes;

Resources::Resources()
{

}


Resources::~Resources()
{
}

Shader* Resources::GetShader(const std::string& id)
{
	if (!_shaders[id])
	{
		if (ResData::ShaderIds.find(id) == ResData::ShaderIds.end())
			throw std::out_of_range("No shader with id:'" + id + "' was defined! Used AddTexture to define textures.");

		_shaders[id] = std::make_unique<Shader>(ResData::ShaderIds[id]);
	}

	return _shaders[id].get();
}

Texture* Resources::AddTexture(const std::string& textureId, const std::string& imageId, bool hasAlpha, const std::string& uniformId)
{
	if (!_textures[textureId])
		_textures[textureId] = std::make_unique<Texture>(textureId, imageId, hasAlpha, uniformId);

	return _textures[textureId].get();
}

Texture* Resources::GetTexture(const std::string& id)
{
	if (!_textures[id])
		throw std::out_of_range("No texture with id:'" + id + "' was defined!");

	return _textures[id].get();
}

Material* Resources::AddMaterial(const std::string& materialId, const std::string& shaderId)
{
	if (!_materials[materialId])
		_materials[materialId] = std::make_unique<Material>(materialId, shaderId);
	return _materials[materialId].get();
}

//if the given material id is not found a new material will be created
Material* Resources::GetMaterial(const std::string& id)
{
	if (!_materials[id])
		return AddMaterial(id, "");

	return _materials[id].get();
}

Mesh* Resources::AddMesh(const std::string& id, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices)
{
	_meshes[id] = std::make_unique<Mesh>(vertices, indices);
	return _meshes[id].get();
}

Mesh* Resources::GetMesh(const std::string& id)
{
	if (!_materials[id])
		throw std::out_of_range("No mesh with id:'" + id + "' was defined! Used AddMesh to define meshes.");

	return _meshes[id].get();
}
