#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-base/GameLogicManager.h"
#include "GameEvents.h"

class GameLogic :
	public SubSystem
{
public:
	GameLogic(GameLogicManager* glm, GameEvents* ge);
	~GameLogic();

	void init();
	void update(float msec);
	void destroy();

	void handleEvents();
	void handleStates();

private:
	GameLogicManager* glm;
	GameEvents* ge;
};

