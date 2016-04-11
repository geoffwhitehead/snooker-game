#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-base/Entity.h"
#include "../engine-base/GameManager.h"

using namespace std;

class GameEvents :
	public SubSystem
{
public:
	GameEvents(GameManager* gm);
	~GameEvents();
	enum EventType { COLLISIONS, SOUND, INPUT, LOGIC };
	enum LogicEvents { RED_POT, WHITE_POT, BLUE_POT, PINK_POT, GREEN_POT, BLACK_POT };

	void init();
	void update(float msec);
	void destroy();
	void clearEvents(EventType);

	GameManager* gm;

	// sorted events - each sub system must handle deletion per frame of their own events
	// collision events
	vector<pair<Entity*, Entity*> > cols_circle_circle;
	vector<pair<Entity*, Entity*> > cols_circle_cushion;
	vector<pair<Entity*, Entity*> > cols_circle_pocket;
	vector<pair<Entity*, Entity*> > cols_cue_pocket;

	// sound events
	vector<std::string> sound_events;

	// input events
	vector<std::string> input_events;

	// game events
	vector<LogicEvents> logic_events;

};

