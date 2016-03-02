#include "CollisionManager.h"


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::init(){

}
void CollisionManager::update(float msec){

}
void CollisionManager::destroy(){

}

void CollisionManager::addObject(Entity* Entity, float* radius){
	Shape* s = new Circle(Entity->getPhysicsObject(), radius);
	collisionEntities.push_back(s);
	Entity->getPhysicsObject()->setRef(s);
}

void CollisionManager::addObject(Entity* Entity, float* x, float* y){
	//collisionEntities.push_back(new Rectangle(entity->getPhysicObject(), x, y));
}


void CollisionManager::removeEntity(Entity* e){
	collisionEntities.erase(std::remove(collisionEntities.begin(), collisionEntities.end(), e->getPhysicsObject()->getRef()), collisionEntities.end());
}