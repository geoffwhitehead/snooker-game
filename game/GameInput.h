#pragma once
#include "../engine-base/SubSystem.h"

class GameInput : public SubSystem
{
public:
	GameInput();
	~GameInput();
	void init();
	void update(float msec);
	void destroy();
};

