#pragma once
#include "object.h"
#include "mesh.h"
#include "../material/material.h"
#include "../../shading/light/lighting_manager.h"

class RenderedObject :public Object
{
public:
	Mesh* mesh;
	Material* material;

public:
	//automatically adds to Draw loop
	RenderedObject();
	RenderedObject(Material* material, Mesh* mesh);
	virtual ~RenderedObject() {}

	void Draw(Camera* camera) override;
	void ApplyLighting(LightingManager::Mode mode = LightingManager::Mode::OneFull);
};

