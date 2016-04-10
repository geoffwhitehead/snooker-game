#pragma once
#include "C:\Users\Geoff\Source\Repos\game-engine\engine-base\SubSystem.h"
#include "../engine-base/SubSystem.h"
#include "../engine-base/GameManager.h"

class GameAudio :
	public SubSystem
{
public:
	GameAudio(GameManager* gm);
	~GameAudio();
	void init();
	void update(float msec);
	void destroy();
private:
	GameManager* gm;
};

