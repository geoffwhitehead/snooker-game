#include "GameLogic.h"



GameLogic::GameLogic(GameLogicManager* glm, GameEvents* ge){

}


GameLogic::~GameLogic()
{
}

void GameLogic::init() {

}

void GameLogic::update(float msec) {
	for (int i = 0; i < ge->logic_events.size(); i++){
		switch (ge->logic_events[i]) {
			case GameEvents::LogicEvents::RED_POT:
					cout << "red pot";
						break;

			case GameEvents::LogicEvents::PINK_POT:
				cout << "pink pot";
				break;
		}
	}
}

void GameLogic::destroy() {

}
