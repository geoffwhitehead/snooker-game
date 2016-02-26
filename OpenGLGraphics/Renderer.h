#pragma once
#include "../nclgl/OGLRenderer.h"

#include "RenderObject.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Physics.h"
#include <ctime>
#include <cstdlib>

const float SNOOKER_WIDTH = 360.0f;
const float SNOOKER_HEIGHT = 180.0f;
const float TABLE_BORDER = 50.0f;



using std::vector;

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	~Renderer(void);
	virtual void	render(const RenderObject *o);
	struct Light {
		Vector3 position;
		float radius;
		Vector3 colour;
	};
	void SetShaderLight(Vector3 position, Vector3 colour, float radius){
		currentLight.position = position;
		currentLight.colour = colour;
		currentLight.radius = radius;
	}

protected:

	void ApplyShaderLight(GLuint program){
		glUniform3fv(glGetUniformLocation(program, "lightColour"), 1, (GLfloat*)&currentLight.colour);
		glUniform3fv(glGetUniformLocation(program, "lightPos"), 1, (GLfloat*)&currentLight.position);
		glUniform1f(glGetUniformLocation(program, "lightRadius"), currentLight.radius);
	}
	Light currentLight;
};

