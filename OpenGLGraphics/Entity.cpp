
#include "Entity.h"

Entity::Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel, Mesh* mesh, Shader* shader, GLuint texture){
	
	this->renderObject = new RenderObject(mesh, shader, texture);;
	this->physicsObject = new PhysicsObject(pos, dir, vel);

}

Entity::Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel, Mesh* mesh, Shader* shader){
	
	this->renderObject = new RenderObject(mesh, shader);;
	this->physicsObject = new PhysicsObject(pos, dir, vel);

}
Entity::Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel){

	this->renderObject = nullptr;
	this->physicsObject = new PhysicsObject(pos, dir, vel);

}

void Entity::setPos(Vector3 v){

}
void Entity::setDir(Vector3 v){

}
void Entity::setVel(Vector3 v){

}

void Entity::translate(Vector3 v){

}
void Entity::scale(Vector3 v){

}
void Entity::rotate(Vector3 v){

}




//destuctor
Entity::~Entity()
{
	if (renderObject) delete renderObject;
	delete physicsObject;
}