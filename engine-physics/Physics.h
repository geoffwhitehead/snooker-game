#pragma once
#include "Windows.h"
#include "../nclgl/Vector3.h"


#define DAMPING_FACTOR 0.92f
#define MINIMUM_VELOCITY 0.000001f

using namespace std;

class Physics
{
public:
	Physics();
	~Physics();

	inline static bool moving(Vector3 &vel) {
		if (abs(vel.x) >= MINIMUM_VELOCITY || abs(vel.y) > MINIMUM_VELOCITY)
			return true;
		else
			vel = Vector3(0.0f, 0.0f, 0.0f);
		return false;
	};

	inline static void calcVelocity(Vector3& vel, Vector3 acc, float dt){
		if (moving(vel))
			vel = (vel + (acc * dt)) * DAMPING_FACTOR;
	}

	inline static void calcDisplacement(Vector3& pos, Vector3 vel, Vector3 acc, float dt, Vector3 disp){
		if (moving(vel)){
			disp = (vel*dt) + (acc * 0.5f * dt*dt);
			pos += disp;
		}
	}

	inline static void semiImplicitEuler(Vector3& pos, Vector3 &vel, Vector3 acc, Vector3& disp, float dt){
		if (moving(vel)) 
			vel = (vel + (acc * dt)) * DAMPING_FACTOR;
		Vector3 new_disp = (disp + (vel * dt)) * DAMPING_FACTOR;
		pos += new_disp;
		disp = new_disp;
	}

	inline static bool detectCollision(Vector3 c1, Vector3 c2, float* r1, float* r2){
		float d2 = pow(c2.x - c1.x, 2.0) + pow(c2.y - c1.y, 2.0) + pow(c2.z - c1.z, 2.0);

		if (d2 < (pow((*r1 + *r2), 2.0))) {
			cout << d2 << endl;

			//calculate p n r and adjust positions with suvat

			return true;
		}
		return false;
	}
	//normal 


	inline static bool detectCollision(Vector3 c1, float* r1, Vector3 normal, float distance){
		float result = c1.Dot((normal), c1) - distance;
		if (abs(result) < *r1){
			return true;
		}
		return false;
	}



};


