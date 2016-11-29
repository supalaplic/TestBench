#pragma once
#include <glfw_init.h>


class Time
{
private:
	static GLfloat _deltaTime;
	static GLfloat _lastFrame;

public:
	void Update();

	static GLfloat DeltaTime() { return _deltaTime; }
	static GLfloat TimeSinceStart() { return glfwGetTime(); }
};

