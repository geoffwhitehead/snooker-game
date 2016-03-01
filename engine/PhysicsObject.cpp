#include "PhysicsObject.h"


PhysicsObject::PhysicsObject(Vector3 pos, Vector3 acc, Vector3 vel){

	this->position = pos;
	this->acceleration = acc;
	this->velocity = vel;
	this->renderObject = nullptr;
}
PhysicsObject::PhysicsObject(Vector3 pos, Vector3 acc, Vector3 vel, RenderObject *r){
	this->position = pos;
	this->acceleration = acc;
	this->velocity = vel;
	this->renderObject = r;
	updateRenderObject();
}
PhysicsObject::~PhysicsObject(){
	
}

Vector3 PhysicsObject::getPos() const{ return position;}
Vector3 PhysicsObject::getAcc() const{ return acceleration;}
Vector3 PhysicsObject::getVel() const{ return velocity;}

void PhysicsObject::setAcc(Vector3 dir){ this->acceleration = dir; };
void PhysicsObject::setVel(Vector3 vel){ this->velocity = vel; };
void PhysicsObject::setPos(Vector3 pos){
	this->position = pos;
	if (renderObject) { updateRenderObject(); };
};

void PhysicsObject::update(float dt) {
	Physics::calcVelocity(this->velocity, this->acceleration, dt);
	Physics::calcDisplacement(this->position, this->velocity, this->acceleration, dt);
	//Physics::implicitEuler(&position, &velocity, acceleration, dt);

	updateRenderObject();
}

