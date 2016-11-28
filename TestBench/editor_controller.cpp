#include "time.h"
#include <glm/gtc/matrix_transform.hpp>
#include "editor_controller.h"
#include "input.h"
#include "camera.h"
#include "debug.h"


EditorController::EditorController(Display* display, GLfloat startPosX, GLfloat startPosY)
{
	Input::OnKey.connect(this, &EditorController::OnKeyAction);
	Input::OnMouseButton.connect(this, &EditorController::OnMouseButtonAction);
	Input::OnScroll.connect(this, &EditorController::OnScrollAction);

	_startPosX = startPosX;
	_startPosY = startPosY;

	SetFreeMode(true);
}


EditorController::~EditorController()
{
	Input::OnKey.disconnect(this, &EditorController::OnKeyAction);
	Input::OnScroll.disconnect(this, &EditorController::OnScrollAction);
}

void EditorController::Update()
{
	//disable controll when window is not focused
	if (!IsEnabled())
		return;


	//move camera with WASD
	Move();
	//rotate camera with mouse
	Look();
}



void EditorController::Move()
{
	GLfloat cameraSpeed = 5.0f * Time::DeltaTime();
	auto cameraPos = Camera::GetMainCamera()->Transform.GetPos();
	auto& trans = Camera::GetMainCamera()->Transform;
	if (Input::KeyPressed(GLFW_KEY_W))
		cameraPos += cameraSpeed * trans.GetForward();
	if (Input::KeyPressed(GLFW_KEY_S))
		cameraPos -= cameraSpeed * trans.GetForward();
	if (Input::KeyPressed(GLFW_KEY_A))
		cameraPos -= glm::normalize(glm::cross(trans.GetForward(), trans.GetUp())) * cameraSpeed;
	if (Input::KeyPressed(GLFW_KEY_D))
		cameraPos += glm::normalize(glm::cross(trans.GetForward(), trans.GetUp())) * cameraSpeed;

	trans.SetPos(cameraPos);
}

void EditorController::Look()
{
	auto cursorPos = Input::CursorPos();
	GLfloat xoffset = cursorPos.x - _startPosX;
	GLfloat yoffset = _startPosY - cursorPos.y; // Reversed since y-coordinates go from bottom to left

	xoffset *= MOVE_SENSITIVITY;
	yoffset *= MOVE_SENSITIVITY;

	_yaw += xoffset;
	_pitch += yoffset;

	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (_pitch > 89.0f)
		_pitch = 89.0f;
	if (_pitch < -89.0f)
		_pitch = -89.0f;

	Camera::GetMainCamera()->Transform.SetRot(glm::vec3(_pitch, -_yaw, 0.0f));
	Input::SetCursorPos(_startPosX, _startPosY);
}

void EditorController::Zoom()
{
	auto camera = Camera::GetMainCamera();
	auto fov = camera->GetFov();
	fov = glm::clamp(fov - Input::ScrollOffset().y * SCROLL_SENSITIVITY, 1.0f, 70.0f);
	camera->SetFov(fov);
}

void EditorController::OnKeyAction(int key, int action)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		SetFreeMode(true);
}

void EditorController::OnScrollAction(float xOffset, float yOffset)
{
	//disable controll when window is not focused
	if (!IsEnabled()) return;

	//change camera FOV with scroll wheel
	Zoom();
}

void EditorController::OnMouseButtonAction(int button, int action)
{
	if (_freeMode && button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		SetFreeMode(false);
}

void EditorController::SetFreeMode(bool value)
{
	if(_freeMode == value)
		 return;

	_freeMode = value;
	if(_freeMode)
	{
		Input::SetCursorMode(GLFW_CURSOR_NORMAL);
	}
	else
	{
		Input::SetCursorMode(GLFW_CURSOR_HIDDEN);
	}
}

bool EditorController::IsEnabled()
{
	return Input::WindowFocused() && !_freeMode;
}
