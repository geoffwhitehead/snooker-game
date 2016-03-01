#pragma once
#include "../engine/SubSystem.h"

class GameInput : public SubSystem
{
public:
	GameInput();
	~GameInput();
	void init();
	void update(float msec);
	void destroy();
};

