#pragma once
#include <memory>
#include <vector>
#include "../engine/core/object/object.h"

class TestScene
{

private:
	std::vector<std::unique_ptr<Object>> _objects;

public:
	TestScene();
	~TestScene();
};

