#pragma once
#include "../engine/SubSystem.h"

class GameInput : public SubSystem
{
public:
	GameInput();
	~GameInput();
	void update(float msec);
	void destroy();
};

