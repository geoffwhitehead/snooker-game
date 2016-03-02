#pragma once
#include "../nclgl/OGLRenderer.h"
#include "RenderObject.h"
#include "Entity.h"
#include "Renderer.h"
#include "SubSystem.h"

// init gm with reference to input handler, ui, camera, audio, memory manager 

class GameManager
{
public:
	GameManager(float, float);
	~GameManager();

	void run();
	void addEntity(Entity*);
	void addSubSystem(SubSystem*);

	GLuint LoadTexture(char* filename, bool textureRepeating = true);

private:
	Window window;
	Renderer renderer;
	vector<Entity*> entities;
	vector<GLuint> textures;
	vector<SubSystem*> subSystems;

	
};

