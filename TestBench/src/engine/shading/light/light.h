#pragma once
#include "../../core/object/transform.h"
#include "../../core/material/shader.h"

#define DEFAULT_LIGHT_ID "light"
class Light
{
public:
	glm::vec3 Ambient = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 Diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 Specular = glm::vec3(1.0f, 1.0f, 1.0f);

protected:
	Transform _transform;

public:
	Light();
	Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	virtual ~Light();

	virtual void SetUniforms(const Shader* shader, const std::string uniformId = "");
	Transform* GetTransform() { return &_transform; }

private:
	Light(const Light& light) {}
	void operator=(const Light& light) const {}
};

