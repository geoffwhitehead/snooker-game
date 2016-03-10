#include "AudioManager.h"


AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

void AudioManager::update(float){

}

void AudioManager::destroy(){


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
