#pragma once
#include "Shape.h"
#include "../engine-base/PhysicsObject.h"

class Circle : public Shape
{
public:
	Circle(PhysicsObject* obj, float* radius);
	~Circle();

private:
	float* radius;
	PhysicsObject* physicsObject;
};

