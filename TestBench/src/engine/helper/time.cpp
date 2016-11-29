#include "time.h"
GLfloat Time::_deltaTime;
GLfloat Time::_lastFrame;


void Time::Update()
{
	GLfloat currentFrame = glfwGetTime();
	_deltaTime = currentFrame - _lastFrame;
	_lastFrame = currentFrame;
}
