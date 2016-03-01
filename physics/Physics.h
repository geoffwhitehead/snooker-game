#pragma once
#include "Windows.h"
#include "../nclgl/Vector3.h"


#define DAMPING_FACTOR 0.85
#define MINIMUM_VELOCITY 0.000001

using namespace std;

class Physics
{
public:
	Physics();
	~Physics();

	float adj_acc;
	

	inline static void calcVelocity(Vector3& vel, Vector3 acc, float dt){
		//if (abs(vel.x) > MINIMUM_VELOCITY || abs(vel.y) > MINIMUM_VELOCITY) {
			vel = (vel + (acc * dt)) * DAMPING_FACTOR;
			//cout << "vel: " << vel << endl;
		//}
		//else {
		//	vel = Vector3(0.0f, 0.0f, 0.0f);
		//}
	}

	inline static Vector3 calcDisplacement(Vector3& pos, Vector3 vel, Vector3 acc, float dt){
		//if (abs(vel.x) > MINIMUM_VELOCITY || abs(vel.y) > MINIMUM_VELOCITY){
		
		return (vel*dt) +(acc * 0.5f * dt*dt);
			//cout << "pos: " << pos << endl;
		//}
	}

	//inline static Vector3 implicitEuler(Vector3& pos, Vector3& vel, Vector3 acc, float dt){
		//adj_acc = 
		//vel = vel + 
	//}

	inline static void semiImplicitEuler(Vector3& pos, Vector3 vel, Vector3 acc, Vector3& disp, float dt){

	}

};

