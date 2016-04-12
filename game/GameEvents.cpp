#include "GameEvents.h"



GameEvents::GameEvents(GameManager* gm){
	this->gm = gm;
}


GameEvents::~GameEvents()
{
}

void GameEvents::init() {

}
 
void GameEvents::handleCollisionEvents() {
	for (int i = 0; i < out_collision_events.size(); i++) {
		switch (out_collision_events[i]) {
		case GameEvents::eCollisionEvents::CE_BALL_BALL:
			for (int i = 0; i < out_cols_circle_circle.size(); i++) {
				in_sound_events.push_back(eSoundEvents::SE_STRIKE_BALL);
			}
			break;
		case GameEvents::eCollisionEvents::CE_BALL_CUSHION:
			for (int i = 0; i < out_cols_circle_cushion.size(); i++) {
				in_sound_events.push_back(eSoundEvents::SE_STRIKE_CUSHION);
			}
			break;
		case GameEvents::eCollisionEvents::CE_BALL_POCKET:
			in_sound_events.push_back(eSoundEvents::SE_POT);
			for (int i = 0; i < out_cols_circle_pocket.size(); i++) {
				if (out_cols_circle_pocket[i].first->sub_group == "red") {
					in_logic_events.push_back(eLogicEvents::LE_POT_RED);
				}
				if (out_cols_circle_pocket[i].first->name == "pink") {
					in_logic_events.push_back(eLogicEvents::LE_POT_PINK);
				}
				if (out_cols_circle_pocket[i].first->name == "white") {
					in_logic_events.push_back(eLogicEvents::LE_POT_WHITE);
					in_sound_events.push_back(eSoundEvents::SE_POT_WHITE);
					changeState(eGameState::GS_PLACE_WHITE);
				}
			}

			break;
		}
	}
}
void GameEvents::handleInputEvents() {
	for (int i = 0; i < out_input_events.size(); i++) {
		switch (out_input_events[i]) {
		case GameEvents::eInputEvents::IE_STRIKE_CUE:
			in_sound_events.push_back(eSoundEvents::SE_STRIKE_CUE);

			break;
		case GameEvents::eInputEvents::IE_WHITE_PLACED:
			in_logic_events.push_back(eLogicEvents::LE_PLACED_WHITE);
			break;
		}
	}
}
void GameEvents::handleLogicEvents() {

}

// the repsonsibility of this function is to handle all the classes [out_*] events
void GameEvents::update(float msec) {
	
	handleCollisionEvents();
	handleInputEvents();
	handleLogicEvents();

}

void GameEvents::destroy() {

}

void GameEvents::in_clearEvents(eEventType et) {
	switch (et)
	{
	case GameEvents::eEventType::ET_SOUND:
		in_sound_events.clear();
		break;
	case GameEvents::eEventType::ET_INPUT:
		in_input_events.clear();
		break;
	case GameEvents::eEventType::ET_LOGIC:
		in_logic_events.clear();
		break;
	}
}

void GameEvents::out_clearEvents(eEventType et) {
	switch (et)
	{
	case eEventType::ET_COLLISIONS:
		out_cols_circle_circle.clear();
		out_cols_circle_cushion.clear();
		out_cols_circle_pocket.clear();
		out_collision_events.clear();
		break;
	case eEventType::ET_INPUT:
		out_input_events.clear();
		break;
	case eEventType::ET_LOGIC:
		out_logic_events.clear();
		break;
	}
}

void GameEvents::changeState(eGameState gs) {
	game_state = gs;
}

Vector3 GameEvents::getMousePos3D() {
	Vector2 pos = gm->getWindow()->GetOSMousePosition();
	Vector2 mPos = gm->getWindow()->convertToScreenCoords(pos);
	return Vector3(mPos.x, mPos.y, 5.0f);
}