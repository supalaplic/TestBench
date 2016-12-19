#pragma once
#include <map>
#include <memory>
#include "material/shader.h"
#include "material/texture.h"
#include "material/material.h"
#include "object/mesh.h"

class Resources
{
public:
private:
	static std::map<std::string, std::unique_ptr<Shader>> _shaders;
	static std::map<std::string, std::unique_ptr<Texture>> _textures;
	static std::map<std::string, std::unique_ptr<Material>> _materials;
	static std::map<std::string, std::unique_ptr<Mesh>> _meshes;


public:
	Resources();
	~Resources();

	//gets and may also instantiate, if the requested shader is not initialized
	static Shader* GetShader(const std::string& id);

	static Texture* AddTexture(const std::string& textureId, const std::string& imageId, bool hasAlpha = false, const std::string& uniformId = "");
	//throws exception when the given texture is not defined
	static Texture* GetTexture(const std::string& id);

	static Material* AddMaterial(const std::string& materialId, const std::string& shaderId);
	//if the given material id is not found a new material will be created
	static Material* GetMaterial(const std::string& id);

	//changes this when onject loading is added
	static Mesh* AddMesh(const std::string& id, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
	//throws exception when the given mesh is not defined
	static Mesh* GetMesh(const std::string& id);

private:
	Resources(const Resources&) { };
	void operator=(const Resources&) {};
};

