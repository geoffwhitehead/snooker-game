
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

void Entity::update(float dt){
	this->physicsObject->update(dt);
	this->renderObject->update(dt);
	for (vector<Entity*>::iterator i = children.begin(); i != children.end(); ++i) {
		(*(*i)).physicsObject->update(dt);
		(*(*i)).renderObject->update(dt);
	}
}

void Entity::render(Renderer* renderer){
	renderer->render(renderObject);
	for (vector<Entity*>::iterator child = children.begin(); child != children.end(); ++child) {
		renderer->render((*child)->renderObject);
	}
}

void Entity::addChild(Entity &child) {
	children.push_back(&child);
	child.parent = this;
	child.renderObject->setParent(this->renderObject);
}

const vector<Entity*>& Entity::GetChildren() const  {
	return children;
}