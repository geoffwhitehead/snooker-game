#include "GameLogic.h"



GameLogic::GameLogic(GameLogicManager* glm, GameEvents* ge){
	this->ge = ge;
	this->glm = glm;
}


GameLogic::~GameLogic()
{
}

void GameLogic::init() {

}

void GameLogic::update(float msec) {
	ge->out_clearEvents(GameEvents::ET_LOGIC);

	handleEvents();
	handleStates();

	ge->in_clearEvents(GameEvents::ET_LOGIC);

}

void GameLogic::destroy() {

}


void GameLogic::handleEvents() {
	for (int i = 0; i < this->ge->in_logic_events.size(); i++) {
		cout << ge->in_logic_events[i];
		switch (ge->in_logic_events[i]) {
		case GameEvents::eLogicEvents::LE_POT_RED:
			cout << "red pot";
			break;

		case GameEvents::eLogicEvents::LE_POT_PINK:
			cout << "pink pot";
			break;

		case GameEvents::eLogicEvents::LE_PLACED_WHITE:
			ge->game_state = GameEvents::eGameState::GS_PLAYING;
		}
	}
}

void GameLogic::handleStates() {
	switch (ge->game_state) {
	case GameEvents::eGameState::GS_PLACE_WHITE:
		Entity* white = ge->gm->getEntityByName("white", "table");
		white->setPos(ge->getMousePos3D());
		break;

	}
}