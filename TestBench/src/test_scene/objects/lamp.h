#pragma once
#include "../../engine/core/object/rendered_object.h"

class Lamp:public RenderedObject
{
public:
	glm::vec3 Color;

	Lamp() {}
	virtual ~Lamp() {}

	void AddMesh(Material* material, Mesh* mesh) override;
	void Draw(Camera* camera) override;
};

