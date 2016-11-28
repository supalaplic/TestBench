#pragma once
#include "display.h"
class EditorController
{
public:
	EditorController(Display* display, GLfloat startPosX, GLfloat startPosY);
	virtual ~EditorController();
	void Update();

	//move cursor freely
	void SetFreeMode(bool value);
private:
	const GLfloat MOVE_SENSITIVITY = 0.05f;
	const GLfloat SCROLL_SENSITIVITY = 2.0f;

	EditorController(const EditorController&) {}
	void operator=(const EditorController&) const {}

	GLfloat _yaw = 0.0f;
	GLfloat _pitch = 0.0f;
	GLfloat _startPosX;
	GLfloat _startPosY;

	//in free mode the user can move the mouse freely but the camera is not controlled
	bool _freeMode;

	//movement functions
	void Move();
	void Look();
	void Zoom();

	void OnKeyAction(int key, int action);
	void OnScrollAction(float xOffset, float yOffset);
	void OnMouseButtonAction(int button, int action);

	bool IsEnabled();
};

