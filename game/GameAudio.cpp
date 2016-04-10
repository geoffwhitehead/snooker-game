#include "GameAudio.h"

#define SOUND_COLLISION "collision"
#define SOUND_GAMEOVER "game_over"
#define SOUND_BG "bg_music"
#define SOUND_CUSHION1 "hit_cushion_1"
#define SOUND_CUSHION2 "hit_cushion_2"
#define SOUND_CUSHION3 "hit_cushion_3"
#define SOUND_CUSHION4 "hit_cushion_4"
#define SOUND_BALL_STRIKE "ball_strike"
#define SOUND_BALL_POT "ball_pot"
#define SOUND_BALL_POT_M "ball_pot_mech"
#define SOUND_BELL "bell"

GameAudio::GameAudio(AudioManager* am, GameEvents* ge)
{
	this->am = am;
	this->ge = ge;
}


GameAudio::~GameAudio()
{
}


void GameAudio::init() {
	
	//am->play2D(SOUND_BG);
}

void GameAudio::update(float msec) {

	for (int i = 0; i < ge->cols_circle_circle.size(); i++) {
		am->play2D(SOUND_BALL_STRIKE);
	}

	for (int i = 0; i < ge->cols_cue_pocket.size(); i++) {
		am->play2D(SOUND_BELL);
	}

	for (int i = 0; i < ge->cols_circle_pocket.size(); i++){
		am->play2D(SOUND_BALL_POT);
	}

	for (int i = 0; i < ge->cols_circle_cushion.size(); i++) {
		/*
		int r = roll(1, 4);

		switch (r) {
		case 1:
			am->play2D(SOUND_CUSHION1);
			break;

		case 2:
			am->play2D(SOUND_CUSHION2);
			break;

		case 3:
			am->play2D(SOUND_CUSHION3);
			break;

		case 4:
			am->play2D(SOUND_CUSHION4);
			break;
		}
		*/
	}
	
}

void GameAudio::destroy() {

}

int GameAudio::roll(int min, int max)
{
	double x = rand() / static_cast<double>(RAND_MAX + 1);

	int r = min + static_cast<int>(x * (max - min));

	return r;
}