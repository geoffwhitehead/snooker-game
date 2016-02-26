#pragma once
#include <vector>
#include "RenderObject.h"

class PhysicsObject
{
private:
	RenderObject* renderObject;
	Vector3 position;
	Vector3 direction;
	Vector3 velocity;
	inline void updateRenderObject(){ 
		this->renderObject->SetModelMatrix(Matrix4::Translation(this->renderObject->GetModelMatrix() * position));
	};

public:
	PhysicsObject(Vector3 pos, Vector3 dir, Vector3 vel);
	PhysicsObject(Vector3 pos, Vector3 dir, Vector3 vel, RenderObject *r);
	~PhysicsObject();

	Vector3 getPos() const;
	Vector3 getDir() const;
	Vector3 getVel() const;
	void setPos(Vector3 v);
	void setDir(Vector3 v);
	void setVel(Vector3 v);
};

