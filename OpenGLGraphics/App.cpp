
#include "App.h"

const float Z = 10.f; // something random for now
const float MAX_VEL = 10.0f; // maximum speed

App::App()
{
	
}


App::~App()
{
}
adadasd

float App::getRandom(float x){
	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / x));
	return r2;
}

void App::print(std::vector<Entity> vec){

	for (int i = 0; i < vec.size(); ++i){

		std::cout << "Entity: " << i << " - AggroRange: " << vec[i].getAggroRange() << " - Entities in Range: " << vec[i].getEntitiesInRange() <<
			" x: " << vec[i].getPos().x << " y: " << vec[i].getPos().y << " z: " << vec[i].getPos().z << endl;

	}
}