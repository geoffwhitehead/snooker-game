#include "GameManager.h"

GameManager::GameManager(float w_x, float w_y)
: window(Window(w_x, w_y)), renderer(Renderer(window)){

}

GameManager::~GameManager(){}
	//for (vector<GLuint>::iterator tex = textures.begin(); tex != textures.end(); ++tex)
		//delete (*tex);


void GameManager::addEntity(Entity* e){
	entityObjects.push_back(e);
}
void GameManager::addSubSystem(SubSystem* ss) {
	subSystems.push_back(ss);
}

void GameManager::run(){
	while (window.UpdateWindow()){
		float msec = window.GetTimer()->GetTimedMS();

		for (vector<SubSystem*>::iterator system = subSystems.begin(); system != subSystems.end(); ++system)
			(*system)->update(msec);

		for (vector<Entity*>::iterator entity = entityObjects.begin(); entity != entityObjects.end(); ++entity)
			(*entity)->update(msec);

		renderer.ClearBuffers();

		for (vector<Entity*>::iterator entity = entityObjects.begin(); entity != entityObjects.end(); ++entity)
			(*entity)->render(&renderer);

		renderer.SwapBuffers();
	}
	for (vector<SubSystem*>::iterator system = subSystems.begin(); system != subSystems.end(); ++system)
		(*system)->destroy();
}

GLuint GameManager::LoadTexture(char* filename, bool textureRepeating){
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