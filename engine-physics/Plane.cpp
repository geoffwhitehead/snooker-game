#include "Plane.h"


Plane::Plane(PhysicsObject* p)
{
	this->physicsObject = p;
	distance = physicsObject->getPos().Length();
	this->normal = physicsObject->getPos();
	this->normal.Normalise();
}


Plane::~Plane()
{
}

Vector3 Plane::getNormal(){
	return normal;
}

float Plane::getDistanceFromOrigin(){
	return distance;
}
