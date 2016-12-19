#include "point_light.h"
#include "lighting_manager.h"
#include "../../helper/camera.h"


PointLight::PointLight()
{
	LightingManager::AddLight(this, LightingManager::LightType::Point);
}


PointLight::~PointLight()
{
	LightingManager::AddLight(this, LightingManager::LightType::Point);
}

void PointLight::SetUniforms(const Shader* shader, const std::string uniformId)
{
	std::string id;
	uniformId.empty() ? id = DEFAULT_POINT_LIGHT_ID : id = uniformId;


	auto pos = Camera::GetMainCamera()->GetView()* glm::vec4(_transform.GetPos(), 1.0f);
	shader->SetUniform3f(id + ".position", pos);

	shader->SetUniform1f(id + ".constant", Constant);
	shader->SetUniform1f(id + ".linear", Linear);
	shader->SetUniform1f(id + ".quadratic", Quadratic);

	Light::SetUniforms(shader, id);
}
