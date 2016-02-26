#pragma once
#include "../nclgl/OGLRenderer.h"
#include <iostream>
#include <vector>
#include "RenderObject.h"
#include "PhysicsObject.h"
#include <string>

using namespace std;

class Entity
{
public:
	Entity();
	Entity(string name, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader, GLuint texture);
	Entity(string name, Vector3 pos, Vector3 acc, Vector3 vel, Mesh* mesh, Shader* shader);
	Entity(string name, Vector3 pos, Vector3 acc, Vector3 vel);

	~Entity();

	void setPos(Vector3 v);
	void setAcc(Vector3 v);
	void setVel(Vector3 v);
	RenderObject* getRenderObject() const;
	
	inline void translate(Vector3 pos){ this->renderObject->SetModelMatrix(this->renderObject->GetModelMatrix() * Matrix4::Translation(pos)); };
	inline void scale(Vector3 scale){ this->renderObject->SetModelMatrix(this->renderObject->GetModelMatrix() * Matrix4::Scale( scale)); };
	inline void rotate(float degree, Vector3 rotation){ this->renderObject->SetModelMatrix(this->renderObject->GetModelMatrix() * Matrix4::Rotation(degree, rotation)); };
	
private:
	PhysicsObject* physicsObject;
	RenderObject* renderObject;
};

