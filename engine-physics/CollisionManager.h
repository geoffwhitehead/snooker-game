#pragma once
#include <vector>
#include "../engine-base/SubSystem.h"
#include "../engine-base/Entity.h"
#include <algorithm>
#include "Circle.h"
#include "Rectangle.h"
#include "Plane.h"

class CollisionManager :
	public SubSystem

{
public:
	void init();
	void update(float msec);
	void destroy();
	CollisionManager();
	~CollisionManager();
	void addObject(Entity* phys_obj, float radius);
	void addObject(Entity* entity, float distance, Vector3 normal);
	void removeEntity(Entity* e);

private:
	vector<PhysicsObject*> collidableSpheres;
	vector<PhysicsObject*> collidablePlanes;

};
