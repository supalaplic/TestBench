#pragma once
#include <string>
#include <GLFW/glfw3.h>

class Display
{
public:
	Display(int width, int height, const std::string title);
	virtual ~Display();
	void Clear(float r, float g, float b, float a);
	void Update();
	int ShouldClose() const;
	GLFWwindow* GetWindow() const { return _window; }
private:
	Display(const Display& other) {}
	void operator=(const Display& other) {}
	GLFWwindow* _window;
};

