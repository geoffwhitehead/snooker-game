#pragma once
#include "../nclgl/OGLRenderer.h"

#include "RenderObject.h"
#include <ctime>
#include <cstdlib>
#include "Entity.h"
#include <vector>
#include "Physics.h"

using std::vector;

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	~Renderer(void);

	virtual void	RenderScene();

	virtual void	Render(const RenderObject &o);

	virtual void	UpdateScene(float msec);

	void	AddRenderObject(RenderObject &r) {
		renderObjects.push_back(&r);
	}

	void	AddEntityObject(Entity *e){
		entityObjects.push_back(e);
	}

	static float getRandom(float);

	GLuint LoadTexture(char* filename, bool textureRepeating = true);

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

	void collisionManager();

protected:
	
	// MANAGERS
	vector<RenderObject*> renderObjects;
	vector<Entity*> entityObjects;

	//MESHES
	Mesh*	mesh_triangle;
	Mesh*	mesh_cube;
	Mesh*	mesh_points;
	Mesh*   mesh_quad;
	Mesh*	mesh_tessMesh;
	Mesh*	mesh_bgMesh;
	Mesh*	mesh_circle;
	Mesh*	mesh_hollowCircle;

	Shader* shader_simple;
	Shader* shader_basic;
	Shader* shader_smiley;
	Shader* shader_blend;
	Shader* shader_perlin;
	Shader* shader_point;
	Shader* shader_tess;
	Shader* shader_light;
	Shader* shader_shrink;
	Shader* shader_tessLight;
	Shader* shader_destroy;
	Shader* shader_hairy;
	Shader* shader_tessCube;


	/*
	RenderObject obj_root;			//ROOT
	RenderObject obj_triObject;
	RenderObject obj_smileyObject;
	RenderObject obj_interpolateObject;
	RenderObject obj_perlinObject;
	RenderObject obj_spritesObject;
	RenderObject obj_tessObject;
	RenderObject obj_lightObject;
	RenderObject obj_shrinkObject;
	RenderObject obj_bgObject;
	RenderObject obj_destroyObject;
	RenderObject obj_hairyObject;
	RenderObject obj_tessCubeObject;
	*/
	GLuint tex_table;

	float i = 1.0;
	float shrink = 1.0;
	float time = 0.0f;

	void ApplyShaderLight(GLuint program){
		glUniform3fv(glGetUniformLocation(program, "lightColour"), 1, (GLfloat*)&currentLight.colour);
		glUniform3fv(glGetUniformLocation(program, "lightPos"), 1, (GLfloat*)&currentLight.position);
		glUniform1f(glGetUniformLocation(program, "lightRadius"), currentLight.radius);
	}
	Light currentLight;
};

