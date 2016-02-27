#pragma once
#include "../nclgl/OGLRenderer.h"
#include "RenderObject.h"
#include "Entity.h"
#include "Renderer.h"
#include "SubSystem.h"



class GameManager
{
public:
	GameManager(float, float);
	~GameManager();
	void run();
	void addEntity(Entity*);
	void addSubSystem(SubSystem*);
	GLuint LoadTexture(char* filename, bool textureRepeating = true);
	Camera* camera;
private:
	Window window;
	Renderer renderer;
	vector<Entity*> entityObjects;
	vector<GLuint> textures;
	vector<SubSystem*> subSystems;

	
};

