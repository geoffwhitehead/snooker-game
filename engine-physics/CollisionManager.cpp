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
					collidableSpheres[i]->getVel(),
					collidableSpheres[j]->getVel(),
					collidableSpheres[i]->getMass(),
					collidableSpheres[j]->getMass(),
					(static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius()),
					(static_cast<Circle*>(collidableSpheres[j]->getRef())->getRadius())
					);
				//if (result) cout << "CIRCLE COLLISION" << i << " : " << j<< endl;
			};
		}
	}
	//PLANES
	for (int i = 0; i < collidableSpheres.size(); i++){
		for (int j = 0; j < collidablePlanes.size(); j++){
			bool result = Physics::detectCollision(
				collidableSpheres[i]->getPos(),
				collidablePlanes[j]->getPos(),
				collidableSpheres[i]->getVel(),
				collidablePlanes[j]->getVel(),
				collidableSpheres[i]->getMass(),
				collidablePlanes[j]->getMass(),
				static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius(),
				static_cast<Plane*>(collidablePlanes[j]->getRef())->getNormal(),
				static_cast<Plane*>(collidablePlanes[j]->getRef())->getDistanceFromOrigin()
				);
			if (result) {
				cout << "PLANE COLLISION" << i << " : " << j << endl;
			}
		}

	}
}
void CollisionManager::destroy(){

}

void CollisionManager::addObject(Entity* entity, float radius){
	Shape* s = new Circle(radius);
	entity->getPhysicsObject()->setRef(s);
	collidableSpheres.push_back(entity->getPhysicsObject());
}

void CollisionManager::addObject(Entity* entity, float distance, Vector3 normal){
	Shape* p = new Plane(distance, normal);
	entity->getPhysicsObject()->setRef(p);
	collidablePlanes.push_back(entity->getPhysicsObject());
}

void CollisionManager::removeEntity(Entity* e){
	collidableSpheres.erase(std::remove(collidableSpheres.begin(), collidableSpheres.end(), e->getPhysicsObject()), collidableSpheres.end());
	collidablePlanes.erase(std::remove(collidablePlanes.begin(), collidablePlanes.end(), e->getPhysicsObject()), collidablePlanes.end());

}