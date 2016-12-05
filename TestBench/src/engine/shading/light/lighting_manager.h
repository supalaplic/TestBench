#pragma once
#include <vector>
#include "light.h"

class LightingManager
{
private:
	static std::vector<Light*> _dirLights;
	static std::vector<Light*> _pointLights;

public:
	enum LightType
	{
		Directional,
		Point
	};

	enum Mode {
		//one directioal light, all rest lights
		OneFull,
		//ode directional light, capped rest of lights
		OneCapped
	};

	LightingManager() {}
	virtual ~LightingManager() {}

	static void AddLight(Light* light, LightType type);
	static void RemoveLight(Light* light, LightType type);

	//applies one directional lights and all the other types
	static void ApplyOneFull(const Shader* shader);

private:
	LightingManager(const LightingManager&) {}
	void operator=(const LightingManager&) const {}

};

