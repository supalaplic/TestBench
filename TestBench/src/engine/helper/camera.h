#pragma once

#include "../core/object/transform.h"

class Camera
{
public:
	Camera(float fov, float aspect, float zNear, float zFar);
	glm::mat4 GetViewProjection();
	glm::mat4 GetView() const;
	glm::mat4 GetProjection();
	Transform Transform;

	void SetFov(float value) { _fov = value; _dirty = true; }
	float GetFov() const { return _fov; }

	//main camera should be the first camera object from the hierarchy
	static Camera* GetMainCamera();

private:
	glm::mat4 _perspective;
	static Camera* _mainCamera;
	float _fov, _aspect, _zNear, _zFar;
	
	//when this is true, perspective is recalculated
	bool _dirty;

	//recalculate perspective
	void Recalculate();
};

