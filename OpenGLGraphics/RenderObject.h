#pragma once

#include "../nclgl/Matrix4.h"
#include "Mesh.h"
#include "Shader.h"
#include "../nclgl/OGLRenderer.h"

class RenderObject	{
public:
	RenderObject(void);
	RenderObject(Mesh*m, Shader*s, GLuint t = 0);
	~RenderObject(void);

	Mesh*	GetMesh()	const			{return mesh;}
	void	SetMesh(Mesh*m)				{mesh = m;}

	Shader* GetShader()		const		{return shader; }
	void	SetShader(Shader*s)			{shader = s;}

	GLuint	GetTexture()		const	{return texture;}
	void	SetTexture(GLuint tex)		{texture = tex;}

	GLuint  GetTexture2() const			{ return texture2;}
	void SetTexture2(GLuint tex)			{ texture2 = tex; }

	void	SetModelMatrix(Matrix4 mat) {modelMatrix = mat;}
	Matrix4 GetModelMatrix()	const	{return modelMatrix;}

	// MODIFIED GEOFF
	void	SetTime(float t) { time = t; }
	void	SetParticleSize(float p_s) { particleSize = p_s; }

	float GetTime()	const	{ return time; }
	float GetParticleSize() const { return particleSize; }

	virtual void Update(float msec);

	virtual void Draw() const;

	//virtual void Update(float msec);

	void	AddChild(RenderObject &child) {
		children.push_back(&child);
		child.parent = this;
	}

	Matrix4 GetWorldTransform() const {
		return worldTransform;
	}

	const vector<RenderObject*>& GetChildren() const  {
		return children;
	}

protected:

	Mesh*	mesh;
	Shader*	shader;

	GLuint	texture;
	GLuint	texture2;

	Matrix4 modelMatrix;
	Matrix4 worldTransform;

	float time;
	float particleSize;

	RenderObject*			parent;
	vector<RenderObject*>	children;

};

