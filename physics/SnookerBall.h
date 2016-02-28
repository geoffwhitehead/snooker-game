#pragma once
#include "../engine/Entity.h"

using namespace std;
class SnookerBall :
	public Entity
{
public:
	SnookerBall(string name, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader, float collision_radius);
	~SnookerBall();

private:
	float collision_radius;

};

