#include "input.h"

GLFWwindow* Input::_window;
glm::vec2 Input::_cursorPos;
glm::vec2 Input::_scrollOffset;
wink::signal<Input::Int2Slot> Input::OnKey;
wink::signal<Input::Int2Slot> Input::OnMouseButton;
wink::signal<Input::ScrollSlot> Input::OnScroll;

Input::Input(const Display* display)
{
	_window = display->GetWindow();

	glfwSetKeyCallback(_window, KeyCallback);
	glfwSetCursorPosCallback(_window, CursorPosCallback);
	glfwSetScrollCallback(_window, ScrollCallback);
	glfwSetMouseButtonCallback(_window, MouseButtonCallback);
}

void Input::Update() const
{
	glfwPollEvents();
}

void Input::CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	_cursorPos.x = xpos;
	_cursorPos.y = ypos;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	OnKey(key, action);
}

void Input::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	_scrollOffset.x = xoffset;
	_scrollOffset.y = yoffset;

	OnScroll(xoffset, yoffset);
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	OnMouseButton(button, action);
}
