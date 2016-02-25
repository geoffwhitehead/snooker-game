#include "PhysicsObject.h"


PhysicsObject::PhysicsObject(Vector3 pos, Vector3 dir, Vector3 vel){

	this->position = pos;
	this->direction = dir;
	this->velocity = vel;
	this->renderObject = nullptr;
}
PhysicsObject::PhysicsObject(Vector3 pos, Vector3 dir, Vector3 vel, RenderObject *r){
	this->position = pos;
	this->direction = dir;
	this->velocity = vel;
	this->renderObject = r;
	updateRenderObject();
}

void PhysicsObject::setPos(Vector3 p){ 
	this->position = p; 
	if (renderObject) { updateRenderObject(); };
};

Vector3 PhysicsObject::getPos() const{ return position;}
Vector3 PhysicsObject::getDir() const{ return direction;}
Vector3 PhysicsObject::getVel() const{ return velocity;}
