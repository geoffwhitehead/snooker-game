
#include "Entity.h"

Entity::Entity(){
	this->name = "def";
	this->renderObject = nullptr;
	this->physicsObject = nullptr;
}

Entity::Entity(string name, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader, GLuint texture){
	
	this->name = name;
	this->renderObject = new RenderObject(pos, mesh, shader, texture);;
	this->physicsObject = new PhysicsObject(pos, acc, vel, renderObject);

}

Entity::Entity(string name, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader){
	this->name = name;
	this->renderObject = new RenderObject(pos, mesh, shader);;
	this->physicsObject = new PhysicsObject(pos, acc, vel, renderObject);
}
Entity::Entity(string name, Vector3 pos, Vector3 acc, Vector3 vel){
	this->name = name;
	this->renderObject = nullptr;
	this->physicsObject = new PhysicsObject(pos, acc, vel);

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
		(*i)->update(dt);
	}
}

void Entity::render(Renderer* renderer){
	renderer->render(renderObject);
	for (vector<Entity*>::iterator child = children.begin(); child != children.end(); ++child) {
		renderer->render((*child)->renderObject);
	}
}

void Entity::addChild(Entity *child) {
	children.push_back(child);
	child->parent = this;
	child->renderObject->setParent(this->renderObject);
}
