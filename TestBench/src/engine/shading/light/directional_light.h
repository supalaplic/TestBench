#pragma once
#include "light.h"

#define DEFAULT_DIRECTIONAL_LIGHT_ID "dirLight"
class DirectionalLight :public Light
{
public:
	DirectionalLight();
	virtual ~DirectionalLight();
	DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) :
		Light(ambient, diffuse, specular) {}

	void SetUniforms(const Shader* shader, const std::string uniformId = "") override;
};

