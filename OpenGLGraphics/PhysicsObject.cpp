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
PhysicsObject::~PhysicsObject(){
	
}



Vector3 PhysicsObject::getPos() const{ return position;}
Vector3 PhysicsObject::getDir() const{ return direction;}
Vector3 PhysicsObject::getVel() const{ return velocity;}
void PhysicsObject::setDir(Vector3 dir){ this->direction = dir; };
void PhysicsObject::setVel(Vector3 vel){ this->direction = vel; };
void PhysicsObject::setPos(Vector3 pos){
	this->position = pos;
	if (renderObject) { updateRenderObject(); };
};