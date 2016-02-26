#pragma once
#include "../nclgl/OGLRenderer.h"
#include "RenderObject.h"
#include "Entity.h"
#include "Renderer.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void run();


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

};
