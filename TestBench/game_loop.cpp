#include <GL/glew.h>
#include "game_loop.h"
#include "time.h"
#include "input.h"
#include "editor_controller.h"
#include "camera.h"
#include "debug.h"
#include "test_scene.h"

std::vector<Object*> GameLoop::_updateObjects;
std::vector<Object*> GameLoop::_drawObjects;

void GameLoop::Loop()
{
	Display display(WIDTH, HEIGHT, "TestingBench");
	Input input(&display);
	Time time;

	Camera camera(70.0f, (float)WIDTH / HEIGHT, 0.1f, 100.0f);
	camera.Transform.SetPos(0.0f, 0.0f, 3.0f);
	EditorController controller(&display, WIDTH / 2.0, HEIGHT / 2.0);
	TestScene cubeManager;

	_drawCamera = &camera;

	while (!display.ShouldClose())
	{
		display.Clear(0.1f, 0.1f, 0.1f, 1.0f);
		time.Update();
		input.Update();
		controller.Update();

		CallLoop(Update);
		CallLoop(Draw);

		//debug draws if any
		Debug::Draw();
		display.Update();
	}
}

void GameLoop::AddToLoop(Object* obj, LoopType loopType)
{
	switch (loopType)
	{
	case Update:
		_updateObjects.push_back(obj);
		break;
	case Draw:
		_drawObjects.push_back(obj);
		break;
	default: break;
	}
}

void GameLoop::RemoveFromLoop(Object* obj, LoopType loopType)
{
	switch (loopType)
	{
	case Update:
		RemoveObject(_updateObjects, obj);
		break;
	case Draw:
		RemoveObject(_drawObjects, obj);
		break;
	default: break;
	}
}

//removing an object from a loop stets it's pointer to nullptr, 
//in order to avoide iterator invalidation if remove is called in the middle of the loop
void GameLoop::RemoveObject(std::vector<Object*>& vec, Object* obj)
{
	auto it = std::find(vec.begin(), vec.end(), obj);
	if (it != vec.end())
		*it = nullptr;
}

void GameLoop::CallLoop(LoopType loopType) const
{
	switch (loopType)
	{
	case Update:
		for (size_t i = 0; i < _updateObjects.size(); i++)
		{
			//test if current object should be removed from loop
			if (_updateObjects[i] == nullptr)
			{
				_updateObjects.erase(_updateObjects.begin() + i);
				i--;
				continue;
			}

			_updateObjects[i]->Update();
		}
		break;
	case Draw:
		for (size_t i = 0; i < _drawObjects.size(); i++)
		{
			//test if current object should be removed from loop
			if (_drawObjects[i] == nullptr)
			{
				_drawObjects.erase(_drawObjects.begin() + i);
				i--;
				continue;
			}
			_drawObjects[i]->Draw(_drawCamera);
		}
		break;
	default: throw std::logic_error("The given looptType was not Implemented: " + loopType);
	}
}
