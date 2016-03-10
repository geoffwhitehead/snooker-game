#pragma once
#include "../engine-base/SubSystem.h"
#include "../_resources/irrKlang-1.5.0/include/irrKlang.h"
#include <iostream>

using namespace irrklang;
using namespace std;


class AudioManager :
	public SubSystem
{
public:
	AudioManager();
	~AudioManager();
	void update(float);
	void destroy();
	void init();


private:
	ISoundEngine* se;

};

