#include "Renderer.h"


Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{
	
	// OPENGL SETTINGS 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	srand(std::time(NULL));

	modelMatrix = Matrix4::Rotation(90, Vector3(1, 0, 0)) * Matrix4::Scale(Vector3(300, 300, 300));
	projMatrix = Matrix4::Orthographic(-20, 50, SNOOKER_WIDTH / 2 + TABLE_BORDER, -SNOOKER_WIDTH / 2 - TABLE_BORDER, SNOOKER_HEIGHT / 2 + TABLE_BORDER, -SNOOKER_HEIGHT / 2 - TABLE_BORDER);

	// SCENE MATRIXES
	//SetProjectionMatrix(Matrix4::Orthographic(1.0f, 500.0f, 1.33f, 45.0f));
	SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
	
}

Renderer::~Renderer(void)	{
	
}


void	Renderer::render(const RenderObject *o) {

	modelMatrix = o->GetWorldTransform();

	if (o->GetShader() && o->GetMesh()) {
		GLuint program = o->GetShader()->GetShaderProgram();

		glUseProgram(program);

		UpdateShaderMatrices(program);
		ApplyShaderLight(program);	

		// Pass in GLuint for time 
		GLint time = glGetUniformLocation(program, "time");
		//glUniform1f(time, o.GetTime());

		Matrix4 rotation = Matrix4(viewMatrix);
		Vector3 invCamPos = viewMatrix.GetPositionVector();
		Vector3 camPos = rotation * -invCamPos; 
		glUniform3fv(glGetUniformLocation(program, "cameraPos"), 1, (GLfloat*)&camPos);

		o->Draw();
	}
}
/*
void	Renderer::UpdateScene(float msec) {
	time += msec;

	for (int i = 0; i < renderObjects.size(); i++) {
		(renderObjects[i]->Update(msec));
	}
	// *************** SCENE MOVEMENT / TEXTURE CHANGE ******************
	// enables you to move the camera around the scene with the defined keys
	if (Keyboard::KeyDown(KEY_A)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(-0.1f * 50, 0, 0));
	};

	if (Keyboard::KeyDown(KEY_D)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.1f * 50, 0, 0));
	}
	if (Keyboard::KeyDown(KEY_W)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.1f * 50, 0));
	}
	if (Keyboard::KeyDown(KEY_S)) {
		viewMatrix = viewMatrix * 
			Matrix4::Translation(Vector3(0.0, -0.1f * 50, 0));
	}

	if (Keyboard::KeyDown(KEY_E)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, 0.1 * 50));
	}
	if (Keyboard::KeyDown(KEY_C)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, -0.1 * 50));
	}
}*/

				   