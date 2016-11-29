#include "game_loop.h"
#include "display.h"
#include <iostream>


Display::Display(int width, int height, const std::string title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (_window == nullptr)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
	}

	int frameBufferWidth, frameBufferHeight;
	glfwGetFramebufferSize(_window, &frameBufferWidth, &frameBufferHeight);

	glViewport(0, 0, frameBufferWidth, frameBufferHeight);
	glEnable(GL_DEPTH_TEST);
}

Display::~Display()
{
	glfwTerminate();
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::Update()
{
	glfwSwapBuffers(_window);
}

int Display::ShouldClose() const
{
	return glfwWindowShouldClose(_window);
}
