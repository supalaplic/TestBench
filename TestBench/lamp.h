#pragma once
#include "rendered_object.h"

class Lamp:public RenderedObject
{
public:
	Lamp() {}
	Lamp(Material* material, Mesh* mesh);
	virtual ~Lamp() {}
};

