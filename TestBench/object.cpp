#include "object.h"
#include "game_loop.h"

Object::Object()
{
	AddToLoop(GameLoop::LoopType::Update);
}

Object::~Object()
{
	if (_inDrawLoop)
		RemoveFromLoop(GameLoop::LoopType::Draw);

	if(_inUpdateLoop)
		RemoveFromLoop(GameLoop::LoopType::Update);
}

void Object::AddToLoop(int loopType)
{
	switch (loopType)
	{
	case GameLoop::Update: 
		if(_inUpdateLoop) return;
		_inUpdateLoop = true;
		break;
	case GameLoop::Draw: 
		if (_inDrawLoop) return;
		_inDrawLoop = true;
		break;
	default: throw std::logic_error("The given looptType was not Implemented: " + loopType);
	}

	GameLoop::AddToLoop(this, static_cast<GameLoop::LoopType>(loopType));
}

void Object::RemoveFromLoop(int loopType)
{
	switch (loopType)
	{
	case GameLoop::Update:
		if (!_inUpdateLoop) return;
		_inUpdateLoop = false;
		break;
	case GameLoop::Draw:
		if (!_inDrawLoop) return;
		_inDrawLoop = false;
		break;
	default: throw std::logic_error("The given looptType was not Implemented: " + loopType);
	}

	GameLoop::RemoveFromLoop(this, static_cast<GameLoop::LoopType>(loopType));
}
