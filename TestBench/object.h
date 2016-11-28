#pragma once
#include "transform.h"
#include "material.h"
#include "mesh.h"
#include "camera.h"

class Object
{
public:
	Material* material;
	Mesh* mesh;

private:
	Transform _transform;


public:
	Object();
	Object(Material* material, Mesh* mesh);
	virtual ~Object();

	virtual void Update() {}
	virtual void Draw(Camera* renderCamera);
	Transform* GatTransform() { return &_transform; }


};

