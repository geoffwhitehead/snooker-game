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

	// circle - circle collisions
	for (int i = 0; i < collidableSpheres.size() - 1; i++){
		//circles
		for (int j = 1; j < collidableSpheres.size(); j++){
			if (collidableSpheres[i] != collidableSpheres[j]) {
				
				// Detect collision
				bool collision = Physics::detectCollision(
					collidableSpheres[i]->getPos(),
					collidableSpheres[j]->getPos(),
					(static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius()),
					(static_cast<Circle*>(collidableSpheres[j]->getRef())->getRadius())
				);

				if (collision) {
					// check that a collision hasnt already occured
					if (collision_map[collidableSpheres[i]][collidableSpheres[j]] == false) {
						Physics::resolveCollision(
							collidableSpheres[i]->getPos(),
							collidableSpheres[j]->getPos(),
							collidableSpheres[i]->getVel(),
							collidableSpheres[j]->getVel(),
							collidableSpheres[i]->getMass(),
							collidableSpheres[j]->getMass(),
							(static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius()),
							(static_cast<Circle*>(collidableSpheres[j]->getRef())->getRadius())
						);
						collision_map[collidableSpheres[i]][collidableSpheres[j]] = true;
						collision_map[collidableSpheres[j]][collidableSpheres[i]] = true;
					}
					else {
						// else do nothing - this collision has already been resolved
					}
				}
				else {
					// else no collision - set both maps to false to mark the objects as not colliding
					collision_map[collidableSpheres[i]][collidableSpheres[j]] = false;
					collision_map[collidableSpheres[j]][collidableSpheres[i]] = false;
				}
			}
		}
	}
	//circle - plane collisions
	for (int i = 0; i < collidableSpheres.size(); i++){
		for (int j = 0; j < collidablePlanes.size(); j++){

			// Detect collision
			bool collision = Physics::detectCollision(
				collidableSpheres[i]->getPos(),
				static_cast<Circle*>(collidableSpheres[i]->getRef())->getRadius(),
				static_cast<Plane*>(collidablePlanes[j]->getRef())->getNormal(),
				static_cast<Plane*>(collidablePlanes[j]->getRef())->getDistanceFromOrigin()
			);

			if (collision) {
				// check that a collision hasnt already occured
				if (collision_map[collidableSpheres[i]][collidablePlanes[j]] == false) {
					Physics::resolveCollision(
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
					collision_map[collidableSpheres[i]][collidablePlanes[j]] = true;
					collision_map[collidablePlanes[j]][collidableSpheres[i]] = true;
				} else {
					// else do nothing - this collision has already been resolved
				}
			}
			else {
				collision_map[collidableSpheres[i]][collidablePlanes[j]] = false;
				collision_map[collidablePlanes[j]][collidableSpheres[i]] = false;
			}
		}
	}

}
void CollisionManager::destroy(){

}

// add circle to the collision manager to enable it to be factored into collision checks
void CollisionManager::addObject(Entity* entity, float radius){
	Shape* s = new Circle(radius);
	entity->getPhysicsObject()->setRef(s);
	collidableSpheres.push_back(entity->getPhysicsObject());
}

// add plane to the collision manager to enable it to be factored into collision checks
void CollisionManager::addObject(Entity* entity, float distance, Vector3 normal){
	Shape* p = new Plane(distance, normal);
	entity->getPhysicsObject()->setRef(p);
	collidablePlanes.push_back(entity->getPhysicsObject());
}

// remove an entity from the collision manager so that it isnt factored into collision checks
void CollisionManager::removeEntity(Entity* e){
	collidableSpheres.erase(std::remove(collidableSpheres.begin(), collidableSpheres.end(), e->getPhysicsObject()), collidableSpheres.end());
	collidablePlanes.erase(std::remove(collidablePlanes.begin(), collidablePlanes.end(), e->getPhysicsObject()), collidablePlanes.end());

}