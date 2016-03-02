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
	for (int i = 0; i < collidableSpheres.size() - 1; i++){
		//SPHERES
		for (int j = 1; j < collidableSpheres.size(); j++){
			if (collidableSpheres[i] != collidableSpheres[j]) {
				
				bool result = Physics::detectCollision(
					collidableSpheres[i]->getPos(),
					collidableSpheres[j]->getPos(),
					(static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius()),
					(static_cast<Circle*>(collidableSpheres[j]->getRef())->getRadius())
					);
				if (result) cout << "CIRCLE COLLISION" << i << " : " << j<< endl;
			};
		}
	}
	//PLANES
	for (int i = 0; i < collidableSpheres.size(); i++){
		for (int j = 0; j < collidablePlanes.size(); j++){
			bool result = Physics::detectCollision(
				collidableSpheres[i]->getPos(),
				static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius(),
				static_cast<Plane*>(collidablePlanes[j]->getRef())->getNormal(),
				static_cast<Plane*>(collidablePlanes[j]->getRef())->getDistanceFromOrigin()
				);
			if (result) cout << "PLANE COLLISION" << i << " : " << j << endl;
		}

	}
}
void CollisionManager::destroy(){

}

void CollisionManager::addObject(Entity* entity, float* radius){
	Shape* s = new Circle(entity->getPhysicsObject(), radius);
	entity->getPhysicsObject()->setRef(s);
	collidableSpheres.push_back(entity->getPhysicsObject());
}

void CollisionManager::addObject(Entity* entity, float* x, float* y){
	//collidableObjects.push_back(new Rectangle(entity->getPhysicObject(), x, y));
}

void CollisionManager::addObject(Entity* entity){
	Shape* p = new Plane(entity->getPhysicsObject());
	entity->getPhysicsObject()->setRef(p);
	collidablePlanes.push_back(entity->getPhysicsObject());
}

void CollisionManager::removeEntity(Entity* e){
	collidableSpheres.erase(std::remove(collidableSpheres.begin(), collidableSpheres.end(), e->getPhysicsObject()), collidableSpheres.end());
	collidablePlanes.erase(std::remove(collidablePlanes.begin(), collidablePlanes.end(), e->getPhysicsObject()), collidablePlanes.end());

}