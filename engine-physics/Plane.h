#pragma once
#include "Shape.h"
#include "../engine-base/PhysicsObject.h"
class Plane :
	public Shape
{
public:
	Plane(PhysicsObject*);
	~Plane();
	PhysicsObject* getPhysicsObject() const { return this->physicsObject; };
	Vector3 getNormal();
	float Plane::getDistanceFromOrigin();
private:
	PhysicsObject* physicsObject;
	float distance;
	Vector3 normal;
};