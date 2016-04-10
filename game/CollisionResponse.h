#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-physics/CollisionManager.h"

class CollisionResponse :
	public SubSystem
{
public:
	CollisionResponse(CollisionManager* cm);
	~CollisionResponse();
	void init();
	void update(float msec);
	void destroy();

	CollisionManager* cm;
	
	// different collisions are handled differently
	vector<pair<Entity*, Entity*> > cols_circle_circle;
	vector<pair<Entity*, Entity*> > cols_circle_cushion;
	vector<pair<Entity*, Entity*> > cols_circle_pocket;
	vector<pair<Entity*, Entity*> > cols_cue_pocket;

};

