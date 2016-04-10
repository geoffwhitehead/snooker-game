#include "AudioManager.h"


AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

void AudioManager::update(float msec){
	for (int i = 0; i < sub_systems.size(); i++){
		sub_systems[i]->update(msec);
	}
}

void AudioManager::destroy(){

}

ISoundSource* AudioManager::loadSound(string name, const ik_c8* path, float default_volume = 1.0f) {
	// create new sound source
	ISoundSource* sound = se->addSoundSourceFromFile(path);
	// set the default volume if specified- 1.0 by default
	sound->setDefaultVolume(default_volume);
	// insert into map, can be accessed later with the name
	audio.insert(pair<string, ISoundSource*>(name, sound));

	return audio[name];

}

void AudioManager::init(){

	// Create the sound engine
	ISoundEngine* se = createIrrKlangDevice();
		
	// check for errors with creation
	if (!se){
		cout << "Error: Could not create Sound Engine" << endl;
	}

	se->play2D("../_resources/irrKlang-1.5.0/media/MF-W-90.XM");


}
