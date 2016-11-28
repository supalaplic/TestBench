#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>


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

