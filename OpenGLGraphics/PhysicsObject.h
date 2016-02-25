#pragma once
#include <vector>
#include "../nclgl/OGLRenderer.h"
#include "RenderObject.h"

class PhysicsObject
{
private:
	RenderObject* renderObject;
	Vector3 position;
	Vector3 direction;
	Vector3 velocity;
	
public:
	PhysicsObject(Vector3 pos, Vector3 dir, Vector3 vel);
	PhysicsObject(Vector3 pos, Vector3 dir, Vector3 vel, RenderObject *r);
	~PhysicsObject();

	void setPos(Vector3);

	Vector3 getPos() const;
	Vector3 getDir() const;
	Vector3 getVel() const;

	inline void translate(Vector3 pos){ this->renderObject->SetModelMatrix(Matrix4::Translation(position)); };
	inline void scale(Vector3 scale){ this->renderObject->SetModelMatrix(Matrix4::Scale(this->renderObject->GetModelMatrix() * scale)); };
	inline void rotate(float degree, Vector3 rotation){ this->renderObject->SetModelMatrix(Matrix4::Rotation(degree, this->renderObject->GetModelMatrix() * rotation)); };

};

