#pragma once
#include "../nclgl/OGLRenderer.h"
#include <iostream>
#include <vector>
#include "RenderObject.h"

using namespace std;

class Entity
{
public:
	Entity();
	~Entity();
	Entity(float, float, float, float, float, float, float, RenderObject*);
	void setPos(Vector3);
	void setDir(Vector3);
	void setAggroRange(float);
	void setEntitiesInRange(int i);
	void incEntity();
	Vector3 getPos() const;
	Vector3 getDir() const;
	float getAggroRange() const;
	int getEntitiesInRange() const;
	friend ostream& operator<<(ostream& os, const Entity& e);
	RenderObject* renderObject;

private:
	Vector3 position;
	Vector3 dir;
	float aggroRange;
	int entitiesInRange = 0;
};

