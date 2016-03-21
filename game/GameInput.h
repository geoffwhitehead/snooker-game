#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-base/GameManager.h"
#include "../nclgl/Window.h"
class GameInput : public SubSystem
{
public:
	GameInput(GameManager* gm);
	~GameInput();
	void init();
	void update(float msec);
	void destroy();
	GameManager* gm;
	
};

