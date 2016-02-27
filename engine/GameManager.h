#pragma once
#include "../nclgl/OGLRenderer.h"
#include "RenderObject.h"
#include "Entity.h"
#include "Renderer.h"
#include "Camera.h"



class GameManager
{
public:
	GameManager();
	~GameManager();
	void run();
	void addEntity(Entity* e);
	GLuint LoadTexture(char* filename, bool textureRepeating = true);
	Camera* camera;
private:
	Window window;
	Renderer renderer;
	vector<Entity*> entityObjects;
	vector<GLuint> textures;

	
};

