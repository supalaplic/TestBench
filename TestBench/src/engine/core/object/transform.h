#pragma once
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	explicit Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
		_pos(pos),
		_scale(scale)
	{
		SetRot(rot);
	}

	glm::mat4 GetModel() const
	{
		auto posMatrix = glm::translate(_pos);
		auto scaleMatrix = glm::scale(_scale);
		auto rotMatrix = glm::mat4_cast(_rot);
		return posMatrix * rotMatrix * scaleMatrix;
	}

	glm::vec3 GetPos() const { return _pos; }
	glm::quat GetRot() const { return _rot; }
	glm::vec3 GetScale() const { return _scale; }
	glm::vec3 GetForward() const { return _rot * _forward; }
	glm::vec3 GetUp() const { return _rot * _up; }
	glm::vec3 GetRight() const { return _rot * _right; }

	void SetPos(const glm::vec3 pos) { _pos = pos; }
	void SetPos(float x, float y, float z) { _pos.x = x; _pos.y = y; _pos.z = z; }
	void SetRot(const glm::vec3 rot)
	{
		_rot = glm::normalize(glm::quat(glm::vec3(glm::radians(rot.x), glm::radians(rot.y), glm::radians(rot.z))));
	}
	void SetScale(const glm::vec3 scale) { _scale = scale; }

	void SetForward(const glm::vec3 forward) { _forward = forward; }
	void SetUp(const glm::vec3 up) { _up = up; }
	void SetRight(const glm::vec3 right) { _right = right; }

private:
	glm::vec3 _pos;
	glm::quat _rot = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 _scale;

	//this can be redefined by the user
	glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 _right = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 _forward = glm::vec3(0.0f, 0.0f, 1.0f);
};
