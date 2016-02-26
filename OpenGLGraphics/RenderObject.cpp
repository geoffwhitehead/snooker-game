#include "RenderObject.h"


RenderObject::RenderObject(void)	{
	mesh	= NULL;
	shader	= NULL;
	texture = NULL;
	parent  = NULL;
}

RenderObject::RenderObject(Mesh*m, Shader*s, GLuint t) {
	mesh	= m;
	shader	= s;
	texture = t;
	parent  = NULL;
}


RenderObject::~RenderObject(void)
{
}


void RenderObject::setParent(RenderObject* r){
	this->parent = r;
}

void RenderObject::update(float msec) {
	if(parent) {
		worldTransform = parent->modelMatrix * modelMatrix;
		//worldTransform = modelMatrix * parent->modelMatrix;
	}
	else {
		worldTransform = modelMatrix;
	}
}

void RenderObject::Draw() const {
	if(mesh) {
		mesh->Draw();
	}
}