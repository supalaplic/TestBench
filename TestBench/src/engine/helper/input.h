#pragma once
#include <glfw_init.h>
#include "../core/display.h"
#include <glm/detail/type_vec2.hpp>
#include <wink/slot.hpp>
#include <wink/signal.hpp>

class Input
{
public:
	typedef wink::slot<void(int, int)> Int2Slot;
	static wink::signal<Int2Slot> OnKey;
	static  wink::signal<Int2Slot> OnMouseButton;

	typedef wink::slot<void(float, float)> ScrollSlot;
	static wink::signal<ScrollSlot> OnScroll;

	explicit Input(const Display* display);
	void Update() const;

	//returns ture as long as the provided key is pressed
	static bool KeyPressed(int key) { return glfwGetKey(_window, key) == GLFW_PRESS; }
	static bool KeyReleased(int key) { return glfwGetKey(_window, key) == GLFW_RELEASE; }

	static glm::vec2 CursorPos() { return _cursorPos; }
	static glm::vec2 ScrollOffset() { return _scrollOffset; }
	static void SetCursorPos(double xPos, double yPos) { glfwSetCursorPos(_window, xPos, yPos); }
	static void SetCursorMode(int mode) { glfwSetInputMode(_window, GLFW_CURSOR, mode); }
	static bool WindowFocused() { return glfwGetWindowAttrib(_window, GLFW_FOCUSED) == 1; }
private:
	Input(const Input&) {}
	void operator=(const Input&) const {}

	static GLFWwindow* _window;
	static glm::vec2 _cursorPos;
	static glm::vec2 _scrollOffset;

	static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};

