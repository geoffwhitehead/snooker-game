#include "GameEvents.h"



GameEvents::GameEvents(GameManager* gm){
	this->gm = gm;
}


GameEvents::~GameEvents()
{
}

void GameEvents::init() {

}

void GameEvents::update(float msec) {
	for (int i = 0; i < cols_cue_pocket.size(); i++) {
		cols_circle_pocket[i].first->is_enabled = false;
	}
}

void GameEvents::destroy() {

}

void GameEvents::clearEvents(EventType et) {
	switch (et)
	{
	case GameEvents::EventType::COLLISIONS:
		cols_circle_circle.clear();
		cols_circle_cushion.clear();
		cols_circle_pocket.clear();
		cols_cue_pocket.clear();
		break;
	case GameEvents::EventType::SOUND:
		sound_events.clear();
		break;
	case GameEvents::EventType::INPUT:
		input_events.clear();
		break;
	case GameEvents::EventType::LOGIC:
		break;
	default:
		break;
	}
}