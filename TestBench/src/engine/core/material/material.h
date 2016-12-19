#pragma once
#include "shader.h"
#include "texture.h"

class Material
{
private:
	std::string _materialId;
	Shader* _shader;
	std::vector<Texture*> _textures;

public:
	Material(const std::string& materialId, Shader* shader) :_materialId(materialId), _shader(shader) {}
	Material(const std::string& materialId, const std::string& shader);
	virtual ~Material() {}

	void AddTexture(const std::string& textureId);
	void Material::AddTexture(Texture* textureId);

	//change this when batching is implemented
	void Bind();

	Shader* GetShader() const { return _shader; }
	void SetShader(Shader* pShader) { _shader = pShader; }
};
