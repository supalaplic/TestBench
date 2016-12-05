#pragma once
#include "../../engine/core/object/rendered_object.h"

class Cube:public RenderedObject
{
public:
	int Index;

public:
	Cube();
	Cube(Material* material, Mesh* mesh);

	virtual ~Cube();

	void Update() override;
	void Draw(Camera* camera) override;
};

