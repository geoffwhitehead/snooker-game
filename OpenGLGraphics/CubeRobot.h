#pragma once
#include "../nclgl/Matrix4.h"
#include "Mesh.h"
#include "Shader.h"
#include "../nclgl/OGLRenderer.h"
#include "renderObject.h"

class CubeRobot
{
public:
	CubeRobot(void);
	~CubeRobot(void);
	virtual void Update(float msec);
};

