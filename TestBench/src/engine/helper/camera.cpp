#include "camera.h"
#include <stdexcept>
Camera* Camera::_mainCamera = nullptr;

Camera::Camera(float fov, float aspect, float zNear, float zFar)
{
	_fov = fov;
	_aspect = aspect;
	_zNear = zNear;
	_zFar = zFar;

	Transform.SetForward(glm::vec3(0, 0, -1));
	_mainCamera = this;
}

glm::mat4 Camera::GetViewProjection()
{
	if (_dirty)
		Recalculate();

	return _perspective * GetView();
}

glm::mat4 Camera::GetView() const
{
	auto pos = Transform.GetPos();
	return glm::lookAt(pos, pos + Transform.GetForward(), Transform.GetUp());
}

glm::mat4 Camera::GetProjection()
{
	if (_dirty)
		Recalculate();

	return _perspective;
}

Camera* Camera::GetMainCamera()
{
	if (_mainCamera == nullptr)
		throw std::out_of_range("No Main Camera is defined!");

	return _mainCamera;
}

void Camera::Recalculate()
{
	_perspective = glm::perspective(glm::radians(_fov), _aspect, _zNear, _zFar);
}
