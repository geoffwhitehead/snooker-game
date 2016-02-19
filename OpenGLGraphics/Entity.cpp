
#include "Entity.h"

//default constructor 
Entity::Entity()
{
	this->position = Vector3(0, 0, 0);
	this->dir = Vector3(0, 0, 0);
	this->aggroRange = 5.0f;
	this->renderObject = NULL;
}

//destuctor
Entity::~Entity()
{
}

Entity::Entity(float x, float y, float z, float agg, float dir_x, float dir_y, float dir_z, RenderObject* r){
	this->position = Vector3(x, y, z);
	this->dir = Vector3(dir_x, dir_y, dir_z);
	this->aggroRange = agg;
	this->renderObject = r;
}

void Entity::setPos(Vector3 v){
	this->position = v;
}

void Entity::setDir(Vector3 v){
	this->dir = v;
}

void Entity::setAggroRange(float agg){
	this->aggroRange = agg;
}
void Entity::setEntitiesInRange(int e){
	this->entitiesInRange = e;
}
void Entity::incEntity(){
	this->entitiesInRange++;
}

Vector3 Entity::getPos() const{
	return position;
}

Vector3 Entity::getDir() const {
	return dir;
}

float Entity::getAggroRange() const{
	return this->aggroRange;
}
int Entity::getEntitiesInRange() const{
	return this->entitiesInRange;
}

ostream& operator<<(ostream& os, const Entity& e)
{
	os << e.getAggroRange() << '/' << e.getEntitiesInRange();
	return os;
}