#pragma once
#include <GL/glew.h>
#include <vector>
#include "object.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

class GameLoop
{

private:
	static std::vector<Object*> _updateObjects;
	static std::vector<Object*> _drawObjects;

	//camera used for the current draw action
	Camera* _drawCamera;

public:
	enum LoopType
	{
		Update,
		Draw
	};

public:
	GameLoop() {}
	virtual ~GameLoop() {}
	void Loop();

	static void AddToLoop(Object* obj, LoopType loopType);
	static void RemoveFromLoop(Object* obj, LoopType loopType);

private:
	GameLoop(const GameLoop&) {};
	void operator=(const GameLoop&) { };

	static void RemoveObject(std::vector<Object*>& vec, Object* obj);
	void CallLoop(LoopType) const;
};

