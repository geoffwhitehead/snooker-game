#include "GameAudio.h"



GameAudio::GameAudio(AudioManager* am)
{
	this->am = am;
}


GameAudio::~GameAudio()
{
}


void GameAudio::init() {
	
	am->play2D("bg_music");
}

void GameAudio::update(float msec) {



}

void GameAudio::destroy() {

}