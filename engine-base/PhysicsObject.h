#pragma once
#include <vector>
#include "RenderObject.h"
#include "../engine-physics/Physics.h"
#include "../engine-physics/Shape.h"

class PhysicsObject
{
private:
	RenderObject* renderObject;
	Vector3 position;
	Vector3 acceleration;
	Vector3 velocity;
	PhysicsObject* parent;
	vector<PhysicsObject*> children;
	inline void updateRenderObject(){
		this->renderObject->SetModelMatrix(Matrix4::Translation(position));
	};
	Vector3 prev_displacement = Vector3(0.0f, 0.0f, 0.0f);
	
	Shape* collision_reference;
public:
	PhysicsObject(Vector3 pos, Vector3 acc, Vector3 vel, PhysicsObject* parent = nullptr);
	PhysicsObject(Vector3 pos, Vector3 acc, Vector3 vel, RenderObject *r, PhysicsObject* parent = nullptr);
	~PhysicsObject();

	Vector3 getPos() const;
	Vector3 getAcc() const;
	Vector3 getVel() const;

	void setPos(Vector3 v);
	void setAcc(Vector3 v);
	void setVel(Vector3 v);

	void update(float dt);

	void setRef(Shape* shape) { this->collision_reference = shape; };
	Shape* getRef() const { return this->collision_reference; };
};