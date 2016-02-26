#pragma once
#include <vector>
#include "RenderObject.h"
#include "Physics.h"

class PhysicsObject
{
private:
	RenderObject* renderObject;
	Vector3 position;
	Vector3 acceleration;
	Vector3 velocity;
	inline void updateRenderObject(){ 
		this->renderObject->SetModelMatrix(Matrix4::Translation(position));
	};

public:
	PhysicsObject(Vector3 pos, Vector3 acc, Vector3 vel);
	PhysicsObject(Vector3 pos, Vector3 acc, Vector3 vel, RenderObject *r);
	~PhysicsObject();

	Vector3 getPos() const;
	Vector3 getAcc() const;
	Vector3 getVel() const;
	void setPos(Vector3 v);
	void setAcc(Vector3 v);
	void setVel(Vector3 v);

	inline void update(float dt) {
		velocity = Physics::calcSUVAT(velocity, acceleration, dt);
		position += Physics::calcDisplacement(velocity, acceleration, dt);
		updateRenderObject();
	}

};

