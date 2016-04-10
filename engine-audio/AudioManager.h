#pragma once
#include "../engine-base/SubSystem.h"
#include "../_resources/irrKlang-1.5.0/include/irrKlang.h"
#include <iostream>
#include <vector>
#include <map>

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
	
	ISoundSource* loadSound(string name, const ik_c8* path, float default_volume = 1.0f);
	vector<SubSystem*> sub_systems;
	ISoundSource* getSound(string name);
	
private:
	ISoundEngine* se;
	map<string, ISoundSource*> audio;
};

