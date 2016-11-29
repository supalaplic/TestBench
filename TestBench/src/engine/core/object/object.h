#pragma once
#include "transform.h"
#include "../../helper/camera.h"

class Object
{
private:
	bool _inUpdateLoop = false;
	bool _inDrawLoop = false;

protected:
	Transform _transform;

public:
	//automatically adds object to Update loop
	Object();
	virtual ~Object();

	virtual void Update() {}
	virtual void Draw(Camera* renderCamera) {}
	Transform* GatTransform() { return &_transform; }

	void AddToLoop(int loopType);
	void RemoveFromLoop(int loopType);

private:
	Object(const Object&) {};
	void operator=(const Object&) const {};

};

