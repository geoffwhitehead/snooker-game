#pragma once
#include "../nclgl/OGLRenderer.h"
#include <iostream>
#include <vector>
#include "RenderObject.h"
#include "PhysicsObject.h";
#include <string>

using namespace std;

class Entity
{
public:
	Entity();
	Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel, Mesh* mesh, Shader* shader, GLuint texture);
	Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel, Mesh* mesh, Shader* shader);
	Entity(string name, Vector3 pos, Vector3 dir, Vector3 vel);

	~Entity();

	void setPos(Vector3);
	void setDir(Vector3);
	void updateObjectMatrix();

private:
	Vector3 position;
	Vector3 dir;
	PhysicsObject* physicsObject;
	RenderObject* renderObject;
};

