#pragma once
#include "object.h"
#include <memory>
#include <vector>

class TestScene
{

private:
	std::vector<std::unique_ptr<Object>> _objects;

public:
	TestScene();
	~TestScene();
};

