#include "directional_light.h"
#include "lighting_manager.h"
#include "../../helper/camera.h"


DirectionalLight::DirectionalLight()
{
	LightingManager::AddLight(this, LightingManager::LightType::Directional);
}

DirectionalLight::~DirectionalLight()
{
	LightingManager::RemoveLight(this, LightingManager::LightType::Directional);
}

void DirectionalLight::SetUniforms(const Shader* shader, const std::string uniformId)
{
	std::string id;
	uniformId.empty() ? id = DEFAULT_DIRECTIONAL_LIGHT_ID : id = uniformId;

	//get the main camera and set directional light direction to be the down vector of the light
	auto dir = glm::transpose(glm::inverse(Camera::GetMainCamera()->GetView())) 
		* glm::vec4(-_transform.GetUp(), 1.0f);
	shader->SetUniform3f(id + ".direction", dir);
	Light::SetUniforms(shader, id);
}
