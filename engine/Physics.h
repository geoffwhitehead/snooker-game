#pragma once

#include "../nclgl/Vector3.h"

class Physics
{
public:
	Physics();
	~Physics();
	inline static Vector3 calcSUVAT(Vector3 vel, Vector3 acc, float dt){
		return vel + (acc * dt);
	}

	inline static Vector3 calcDisplacement(Vector3 vel, Vector3 acc, float dt){
		return (vel*dt) + (acc * 0.5f * dt*dt);
	}

};

