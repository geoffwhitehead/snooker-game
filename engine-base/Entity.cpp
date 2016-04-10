
#include "Entity.h"

Entity::Entity(){
	this->name = "default";
	this->renderObject = nullptr;
	this->physicsObject = nullptr;
	this->renderable = true;
}

Entity::Entity(string name, string group, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader, GLuint texture){
	
	this->name = name;
	this->group = group;
	this->renderObject = new RenderObject(pos, mesh, shader, texture);;
	this->physicsObject = new PhysicsObject(pos, acc, vel, renderObject);
	this->renderable = true;
}

Entity::Entity(string name, string group, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader){
	this->name = name;
	this->group = group;
	this->renderObject = new RenderObject(pos, mesh, shader);;
	this->physicsObject = new PhysicsObject(pos, acc, vel, renderObject);
	this->renderable = true;
}
Entity::Entity(string name, string group, Vector3 pos, Vector3 acc, Vector3 vel){
	this->name = name;
	this->group = group;
	this->renderObject = nullptr;
	this->physicsObject = new PhysicsObject(pos, acc, vel);
	this->renderable = true;
}

void Entity::setPos(Vector3 pos){ this->physicsObject->setPos(pos); }
void Entity::setAcc(Vector3 dir){ this->physicsObject->setAcc(dir); }
void Entity::setVel(Vector3 vel){ this->physicsObject->setVel(vel); }
void Entity::setMass(float mass){ this->physicsObject->setMass(mass); };


//destuctor
Entity::~Entity()
{
	if (renderObject) delete renderObject;
	delete physicsObject;
}

RenderObject* Entity::getRenderObject() const {
	return this->renderObject;
}

PhysicsObject* Entity::getPhysicsObject() const {
	return this->physicsObject;
}

void Entity::update(float dt){
	if (is_enabled) {
		this->physicsObject->update(dt);
		this->renderObject->update(dt);
	}
	for (vector<Entity*>::iterator i = children.begin(); i != children.end(); ++i)
		(*i)->update(dt);
	
		
}

void Entity::render(Renderer* renderer){
	
	if (this->renderable && this->is_enabled){
		renderer->render(renderObject);
	}

	for (vector<Entity*>::iterator child = children.begin(); child != children.end(); ++child)
		(*child)->render(renderer);
}

void Entity::addChild(Entity *child) {
	children.push_back(child);
	child->parent = this;
	child->renderObject->setParent(this->renderObject);
}
vector<Entity*> Entity::getChildren(){
	return this->children;
}

