#pragma once
#include "object.h"
#include "mesh.h"
#include "../material/material.h"
#include "../../shading/light/lighting_manager.h"

class RenderedObject :public Object
{
protected:
	std::vector<Mesh*> _meshes;
	std::vector<Material*> _materials;

public:
	//automatically adds to Draw loop
	RenderedObject();
	virtual ~RenderedObject() {}

	virtual void AddMesh(Material* material, Mesh* mesh);
	void Draw(Camera* camera) override;
	void ApplyLighting(LightingManager::Mode mode = LightingManager::Mode::OneFull);
};

