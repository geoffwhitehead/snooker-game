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
#define SOUND_CUE_1 "cue_strike_1"
#define SOUND_CUE_2 "cue_strike_2"


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

	for (int i = 0; i < ge->in_sound_events.size(); i++) {
		switch (ge->in_sound_events[i]) {
		case GameEvents::SE_POT:
			am->play2D(SOUND_BALL_POT);
			break;

		case GameEvents::SE_STRIKE_BALL:
			am->play2D(SOUND_BALL_STRIKE);
			break;

		case GameEvents::SE_POT_WHITE:
			am->play2D(SOUND_BELL);
			break;

		case GameEvents::SE_STRIKE_CUE:
			int r = roll(0, 2);
			switch (r) {
			case 0:
				am->play2D(SOUND_CUE_1);
				break;

			case 1:
				am->play2D(SOUND_CUE_2);
				break;
			}
			break;
			/*
			case GameEvents::SE_STRIKE_CUSHION:
			
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
			break;
			*/
		}

	}

	// clear events now that they have been actioned
	ge->in_clearEvents(GameEvents::ET_SOUND);
	
}

void GameAudio::destroy() {

}

int GameAudio::roll(int min, int max)
{
	double x = rand() / static_cast<double>(RAND_MAX + 1);

	int r = min + static_cast<int>(x * (max - min));

	return r;
}