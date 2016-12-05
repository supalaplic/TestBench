#pragma once
#include "../../engine/core/object/rendered_object.h"

class Lamp:public RenderedObject
{
public:
	glm::vec3 Color;

	Lamp() {}
	Lamp(Material* material, Mesh* mesh);
	virtual ~Lamp() {}

	void Draw(Camera* camera) override;
};

