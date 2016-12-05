#pragma once
#include "src/engine/shading/light/light.h"

#define DEFAULT_POINT_LIGHT_ID "pointLight"
class PointLight:public Light
{
public:
	float Constant = 1.0f;
	float Linear = 0.09f;
	float Quadratic = 0.032f;

public:
	PointLight();
	virtual ~PointLight();

	void SetUniforms(const Shader* shader, const std::string uniformId = "") override;
};

