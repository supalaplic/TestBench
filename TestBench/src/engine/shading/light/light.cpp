#include "light.h"


Light::Light()
{
}

Light::Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) :
	Ambient(ambient),
	Diffuse(diffuse),
	Specular(specular) {
}

Light::~Light()
{
}

void Light::SetUniforms(const Shader* shader, const std::string uniformId)
{
	std::string id;
	uniformId.empty() ? id = DEFAULT_LIGHT_ID : id = uniformId;

	shader->SetUniform3f(id + ".ambient", Ambient);
	shader->SetUniform3f(id + ".diffuse", Diffuse);
	shader->SetUniform3f(id + ".specular", Specular);
}
