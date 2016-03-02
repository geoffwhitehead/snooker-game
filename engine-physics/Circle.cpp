#include "Circle.h"


Circle::Circle(PhysicsObject* obj, float* radius){
	this->radius = radius;
	this->physicsObject = obj;
}


Circle::~Circle()
{
}
