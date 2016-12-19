#include "lighting_manager.h"

std::vector<Light*> LightingManager::_dirLights;
std::vector<Light*> LightingManager::_pointLights;


void LightingManager::AddLight(Light* light, LightType type)
{
	switch (type)
	{
	case Directional: 
		_dirLights.push_back(light);
		break;
	case Point: 
		_pointLights.push_back(light);
		break;
	default: break;
	}
}

void LightingManager::RemoveLight(Light* light, LightType type)
{
	switch (type)
	{
	case Directional:
		_dirLights.erase(std::find(_dirLights.begin(), _dirLights.end(), light));
		break;
	case Point: 
		_pointLights.erase(std::find(_pointLights.begin(), _pointLights.end(), light));
		break;
	default: break;
	}
}

void LightingManager::ApplyOneFull(const Shader* shader)
{
	if (_dirLights.size() > 0)
		_dirLights[0]->SetUniforms(shader);

	for (size_t i = 0; i < _pointLights.size(); i++)
		_pointLights[i]->SetUniforms(shader, "pointLights[" + std::to_string(i) + "]");
}

