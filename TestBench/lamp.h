#pragma once
#include "camera.h"
#include "object.h"

class Lamp:public Object
{
public:
	Lamp() {}
	Lamp(Material* material, Mesh* mesh);
	virtual ~Lamp() {}


};

