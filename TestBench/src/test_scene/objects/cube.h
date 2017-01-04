#pragma once
#include "../../engine/core/object/rendered_object.h"

class Cube:public RenderedObject
{
public:
	int Index;

public:
	Cube();
	virtual ~Cube();

	void AddMesh(Material* material, Mesh* mesh) override;
	void Update() override;
	void Draw(Camera* camera) override;
};

