
#include "Entity.h"

Entity::Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel, Mesh* mesh, Shader* shader, GLuint texture){
	
	this->renderObject = new RenderObject(mesh, shader, texture);;
	this->physicsObject = new PhysicsObject(pos, dir, vel, renderObject);

}

Entity::Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel, Mesh* mesh, Shader* shader){
	this->renderObject = new RenderObject(mesh, shader);;
	this->physicsObject = new PhysicsObject(pos, dir, vel, renderObject);
}
Entity::Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel){

	this->renderObject = nullptr;
	this->physicsObject = new PhysicsObject(pos, dir, vel);

}

void Entity::setPos(Vector3 pos){ this->physicsObject->setPos(pos); }
void Entity::setAcc(Vector3 dir){ this->physicsObject->setAcc(dir); }
void Entity::setVel(Vector3 vel){ this->physicsObject->setVel(vel); }

//destuctor
Entity::~Entity()
{
	if (renderObject) delete renderObject;
	delete physicsObject;
}

RenderObject* Entity::getRenderObject() const {
	return this->renderObject;
}