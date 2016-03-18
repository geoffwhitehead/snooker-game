#include "GameManager.h"

GameManager::GameManager(float w_x, float w_y)
: window(Window(w_x, w_y)), renderer(Renderer(window)){

}

GameManager::~GameManager(){}
	//for (vector<GLuint>::iterator tex = textures.begin(); tex != textures.end(); ++tex)
		//delete (*tex);


void GameManager::addEntity(Entity* e){
	entities.push_back(e);
}
void GameManager::addSubSystem(SubSystem* ss) {
	subSystems.push_back(ss);
}

void GameManager::run(){
	
	for (vector<SubSystem*>::iterator system = subSystems.begin(); system != subSystems.end(); ++system)
		(*system)->init();

	while (window.UpdateWindow()){
		float msec = window.GetTimer()->GetTimedMS();

		msec *= 2.0f;

		// TEMP CODE

		Entity* white = entities[0]->getChildren()[0];

		if (Keyboard::KeyDown(KEY_Z))
			white->setVel(Vector3(0.031f, 0.0007f, 0.0f));

		Vector2 mPos = window.GetOSMousePosition();
		white->getPhysicsObject()->setPos(Vector3(mPos.x, mPos.y, 0.0f));
		// ENGINE SYSTEMS

		for (vector<SubSystem*>::iterator system = subSystems.begin(); system != subSystems.end(); ++system)
			(*system)->update(msec);

		for (vector<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
			(*entity)->update(msec);

		renderer.ClearBuffers();

		for (vector<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
			(*entity)->render(&renderer);

		renderer.SwapBuffers();
	}
	for (vector<SubSystem*>::iterator system = subSystems.begin(); system != subSystems.end(); ++system)
		(*system)->destroy();
}

GLuint GameManager::LoadTexture(const char* filename, bool textureRepeating){
	GLuint texture = SOIL_load_OGL_texture(filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
		);

	if (texture == NULL){
		printf("[Texture loader] \"%s\" failed to load!\n", filename);
		return 0;
	}
	else
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureRepeating ? GL_REPEAT : GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureRepeating ? GL_REPEAT : GL_CLAMP);

		glActiveTexture(0);
		textures.push_back(texture);
		return texture;
	}
}