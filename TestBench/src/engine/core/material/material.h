#pragma once
#include "shader.h"
#include "texture.h"

class Material
{
private:
	std::string _id;
	Shader* _shader;
	Texture* _texture;

public:
	Material(const std::string& id, Shader* shader, Texture* texture) :_id(id), _shader(shader), _texture(texture) {}

	//initializes and loads into memory the given shader/texture
	Material(const std::string& id, const std::string& shaderId, const std::string& textureId);
	virtual ~Material() {}

	//remove this when batching is implemented
	void Bind();

	Shader* GetShader() const { return _shader; }
	void SetShader(Shader* pShader) { _shader = pShader; }
	Texture* GetTexture() const { return _texture; }
	void SetTexture(Texture* pTexture) { _texture = pTexture; }
};
