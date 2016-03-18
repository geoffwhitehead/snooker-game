#pragma once
#include "Windows.h"
#include "../nclgl/Vector3.h"


#define DAMPING_FACTOR 0.98f
#define MINIMUM_VELOCITY 0.0001f
#define COEFF_OF_ELASTICITY 0.9f
#define SRRING_STRENGTH 0.8f 
#define CLAMP 0.05f

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
		
			vel = (vel + (acc * dt)) * DAMPING_FACTOR;
		
		//clamp
		if (vel.Length() > CLAMP){
			Vector3 unit = vel.getNormal();
			vel = unit * CLAMP;
		}
			
	}

	inline static void calcDisplacement(Vector3& pos, Vector3 vel, Vector3 acc, float dt, Vector3& disp){
		if (moving(vel)){
			disp = ((vel*dt) + (acc * 0.5f * dt*dt));
			pos += disp;
		}
	}

	inline static void semiImplicitEuler(Vector3& pos, Vector3 &vel, Vector3 acc, Vector3& disp, float dt){
		if (moving(vel))
			calcVelocity(vel, acc, dt);

		calcDisplacement(pos, vel, acc, dt, disp);
		
		//Vector3 new_disp = (disp + (vel * dt)) * DAMPING_FACTOR;
		//pos += new_disp;
		//disp = new_disp;
	}

	inline static bool detectCollision(Vector3& pos1, Vector3& pos2, Vector3& vel1, Vector3& vel2, float mass1, float mass2, float r1, float r2){
		float d2 = pow(pos2.x - pos1.x, 2.0) + pow(pos2.y - pos1.y, 2.0) + pow(pos2.z - pos1.z, 2.0);

		if (d2 < (pow((r1 + r2), 2.0))) {

			//calculate penetration depth
			float p = r1 + r2 - sqrt(d2);
			
			//calculate point of collision
			//Vector3 P = pos1 - N * (r1 - p);

			//calculate collision normal
			Vector3 N = (pos1 - pos2).getAbs();

			Vector3 Vab = vel1 + vel2;

			float VN = Vab.dot(N);

			//float totalForce = -COEFF_OF_ELASTICITY * (vel1 + vel2).dot(N);

			float J = (-(1+COEFF_OF_ELASTICITY) * VN) / (N.dot(N)*((1/mass1) + (1/mass2)));

			float spring_vel = N.dot(Vab);

			//float F = (-SRRING_STRENGTH) * p - (DAMPING_FACTOR * (N.dot(Vab)));

			vel1 = vel1 - (N * (J / mass1));
			vel2 = vel2 + (N * (J / mass2));

			return true;
		}
		return false;
	}
	//normal 


	inline static bool detectCollision(Vector3& c_pos, Vector3& p_pos, Vector3& c_vel, Vector3& p_vel, float c_mass, float p_mass, float r, Vector3 normal, float distance){
		float result = c_pos.Dot((normal), c_pos) - distance;
		if (abs(result) < r){
			
			Vector3 N = normal;
			float p = r - result; // this might not be right regarding distance 
			Vector3 P = c_pos - N * (r - p);

			Vector3 Vab = c_vel + p_vel;

			float VN = Vab.dot(N);

			//float totalForce = -COEFF_OF_ELASTICITY * (vel1 + vel2).dot(N);

			float J = (-(1 + COEFF_OF_ELASTICITY) * VN) / (N.dot(N)*((1 / c_mass) + (1 / p_mass)));

			c_vel = c_vel - (N * (J / c_mass));
			p_vel = p_vel + (N * (J / p_mass));
			
			return true;
		}
		return false;
	}



};


