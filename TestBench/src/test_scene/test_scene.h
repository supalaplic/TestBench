#pragma once
#include <memory>
#include <vector>
#include "../engine/core/object/object.h"
#include "../engine/shading/light/light.h"

class TestScene
{

private:
	std::vector<std::unique_ptr<Object>> _objects;
	std::vector<std::unique_ptr<Light>> _lights;

public:
	TestScene();
	~TestScene();
};

