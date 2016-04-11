#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-audio/AudioManager.h"
#include "../game/GameEvents.h"

class GameAudio :
	public SubSystem
{
public:
	GameAudio(AudioManager* am, GameEvents* ge);
	~GameAudio();
	void init();
	void update(float msec);
	void destroy();

	int roll(int min, int max);
private:
	AudioManager* am;
	GameEvents* ge;
};

