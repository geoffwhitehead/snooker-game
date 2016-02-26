#include "GameManager.h"

const float WINDOW_X = 1024;
const float WINDOW_Y = 768;


GameManager::GameManager()
: window(Window(WINDOW_X, WINDOW_Y)), renderer(Renderer(window)){

}

GameManager::~GameManager(){
	// TODO delete textures
}

void GameManager::addEntity(Entity* e){
	entityObjects.push_back(e);
}

void GameManager::run(){

	Camera* camera = new Camera(0.0f, 0.0f, Vector3(0, 0, 400));
	Camera::projMatrix = Matrix4::Perspective(1, 1000, 1024.0f / 768.0f, 45);
	Camera::viewMatrix = camera->BuildViewMatrix();
	
	while (window.UpdateWindow()){
		float msec = window.GetTimer()->GetTimedMS();
		camera->UpdateCamera(msec);
		for (vector<Entity*>::iterator entity = entityObjects.begin(); entity != entityObjects.end(); ++entity)
			(*entity)->update(msec);

		renderer.ClearBuffers();

		for (vector<Entity*>::iterator entity = entityObjects.begin(); entity != entityObjects.end(); ++entity)
			(*entity)->render(&renderer);

		renderer.SwapBuffers();
	}
	/*
	// *************** SCENE MOVEMENT / TEXTURE CHANGE ******************
	// enables you to move the camera around the scene with the defined keys
	if (Keyboard::KeyDown(KEY_A)) {
		Camera::viewMatrix = Camera::viewMatrix *
			Matrix4::Translation(Vector3(-0.1f * 50, 0, 0));
	};

	if (Keyboard::KeyDown(KEY_D)) {
		Camera::viewMatrix = Camera::viewMatrix *
			Matrix4::Translation(Vector3(0.1f * 50, 0, 0));
	}
	if (Keyboard::KeyDown(KEY_W)) {
		Camera::viewMatrix = Camera::viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.1f * 50, 0));
	}
	if (Keyboard::KeyDown(KEY_S)) {
		Camera::viewMatrix = Camera::viewMatrix *
			Matrix4::Translation(Vector3(0.0, -0.1f * 50, 0));
	}

	if (Keyboard::KeyDown(KEY_E)) {
		Camera::viewMatrix = Camera::viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, 0.1 * 50));
	}
	if (Keyboard::KeyDown(KEY_C)) {
		Camera::viewMatrix = Camera::viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, -0.1 * 50));
	}
*/
	
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