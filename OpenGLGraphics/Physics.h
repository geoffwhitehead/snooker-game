#pragma once

#include "../nclgl/Vector3.h"

class Physics
{
public:
	Physics();
	~Physics();
	inline Vector3 calcSUVAT(Vector3 u, Vector3 a, float t){
		return u + a * t;
	}

	inline Vector3 calcDisplacement(Vector3 u, Vector3 a, float t){
		return (u*t) + (a * 0.5f * t*t);
	}

};

