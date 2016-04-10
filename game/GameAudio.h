#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-audio/AudioManager.h"

class GameAudio :
	public SubSystem
{
public:
	GameAudio(AudioManager* am);
	~GameAudio();
	void init();
	void update(float msec);
	void destroy();
private:
	AudioManager* am;
};

