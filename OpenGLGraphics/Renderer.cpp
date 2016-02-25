#include "Renderer.h"
#include <ctime>
#include <cstdlib>

const float Z = 10.f; // something random for now
const float MAX_VEL = 10.0f; // maximum speed
const float X_BOUND = 20.0f-1;
const float Y_BOUND = 20.0f-1;
const float GAME_DEPTH = -20.0f;
const float MAX_VELOCITY = 1.5f;
const float SNOOKER_WIDTH = 360.0f;
const float SNOOKER_HEIGHT = 180.0f;
const float TABLE_BORDER = 50.0f;
const float CUSHION_WIDTH = 18.0f;
const float POCKET_WIDTH = 63.0f;


const Vector4 RED = Vector4(1.0f,1.0f,255.0f,1.0f);



Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{
	
	// OPENGL SETTINGS 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	srand(std::time(NULL));

	modelMatrix = Matrix4::Rotation(90, Vector3(1, 0, 0)) * Matrix4::Scale(Vector3(300, 300, 300));
	projMatrix = Matrix4::Orthographic(0, 50, SNOOKER_WIDTH / 2 + TABLE_BORDER, -SNOOKER_WIDTH / 2 - TABLE_BORDER, SNOOKER_HEIGHT / 2 + TABLE_BORDER, -SNOOKER_HEIGHT / 2 - TABLE_BORDER);

	// SCENE MATRIXES
	//SetProjectionMatrix(Matrix4::Orthographic(1.0f, 500.0f, 1.33f, 45.0f));
	SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
	
	//SHADERS
	shader_basic = new Shader("./shaders/basicVert.glsl", "./shaders/basicFrag.glsl");
	shader_simple = new Shader("./shaders/textureVert.glsl", "./shaders/textureFrag.glsl");

	//MESHES
	mesh_triangle = Mesh::GenerateTriangle();
	mesh_circle = Mesh::GenerateTriFan();
	mesh_hollowCircle = Mesh::GenerateTriFanBorder();
	mesh_bgMesh = Mesh::GeneratePoints(1);
	mesh_tessMesh = Mesh::GenerateQuadPatch();
	mesh_quad = Mesh::GenerateQuad();

	//TEXTURES
	tex_table = LoadTexture("./textures/snooker_table.png");

	glUniform1f(c1.SetColour(), RED);

	
	//ENTITIES
	
	//POSITION TRANSFORMS
	
	
	// SCALE TRANSFORMS
	tbl_top.SetModelMatrix(Matrix4::Translation(Vector3(0, SNOOKER_HEIGHT / 2 - CUSHION_WIDTH, 0)) * Matrix4::Scale(Vector3(SNOOKER_WIDTH - POCKET_WIDTH, 3, 1)));
	tbl_right.SetModelMatrix(Matrix4::Translation(Vector3(SNOOKER_WIDTH / 2 - CUSHION_WIDTH, 0, 0)) * Matrix4::Scale(Vector3(3, SNOOKER_HEIGHT - POCKET_WIDTH, 1)));
	tbl_bottom.SetModelMatrix(Matrix4::Translation(Vector3(0, -SNOOKER_HEIGHT / 2 + CUSHION_WIDTH, 0)) * Matrix4::Scale(Vector3(SNOOKER_WIDTH - POCKET_WIDTH, 3, 1)));
	tbl_left.SetModelMatrix(Matrix4::Translation(Vector3(-SNOOKER_WIDTH / 2 + CUSHION_WIDTH, 0, 0)) * Matrix4::Scale(Vector3(3, SNOOKER_HEIGHT - POCKET_WIDTH, 1)));

	obj_Table.SetModelMatrix(obj_Table.GetModelMatrix() * (Matrix4::Scale(Vector3(SNOOKER_WIDTH, SNOOKER_HEIGHT, 1))));


	AddEntityObject(new Entity("red1", Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red2", Vector3(3.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red2", Vector3(3.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red3", Vector3(5.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red4", Vector3(7.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red5", Vector3(9.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red6", Vector3(11.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red7", Vector3(13.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red8", Vector3(15.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red9", Vector3(17.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red10", Vector3(19.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red11", Vector3(21.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red12", Vector3(23.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red13", Vector3(25.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red14", Vector3(27.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red15", Vector3(29.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));

	AddEntityObject(new Entity("yellow", Vector3(31.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic);
	AddEntityObject(new Entity("blue", Vector3(33.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic);
	AddEntityObject(new Entity("pink", Vector3(35.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic);
	AddEntityObject(new Entity("black", Vector3(37.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic);

	AddEntityObject(new Entity("table_left", Vector3(29.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	AddEntityObject(new Entity("table_right", Vector3(31.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	AddEntityObject(new Entity("table_bottom", Vector3(33.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	AddEntityObject(new Entity("table_top", Vector3(35.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	AddEntityObject(new Entity("table", Vector3(37.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_simple, tex_table);

}



float Renderer::getRandom(float x){
	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / x));
	return r2;
}

/*
void Renderer::collisionManager(){

}

void Renderer::gameManager(){

}

void Renderer::physicsManager(){

}

void Renderer::resourceManager(){

}
*/

// SHOULD ENTITIES HAVE FLAGS TO SAY WHETHER THESE OBJECT ARE AFFECTED BY PHYSICS / COLLISIONS?

//

// ARE ALL THE MANAGERS CLASSES OR FUNCTIONS?

// SHOULD I HAVE AN ENCOMPASSING CLASS TO HOLD ALL THE MANAGERS OR NEST THEM WITHIN THE RENDERER?

// WHERE TO HANDLE ENTITY MOVEMENT AND GAME LOGIC?

// WHERE TO STORE ALL THE MESHES AND TEXTURES THAT ARE GETTING LOADED IN?... RESOURCE MANAGER?

/// create the gamemanager which will manage entities, pass render objects to the renderer by passing a rendering node. 

Renderer::~Renderer(void)	{
	
	//DELETE MESHES
	delete triangle;
}

void	Renderer::RenderScene() {
	ClearBuffers();
	Render(root);
	
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		Render(*(*i));
	}
}

void	Renderer::Render(const RenderObject &o) {

	modelMatrix = o.GetWorldTransform();

	if (o.GetShader() && o.GetMesh()) {
		GLuint program = o.GetShader()->GetShaderProgram();

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

		o.Draw();
	}

	for (vector<RenderObject*>::const_iterator i = o.GetChildren().begin(); i != o.GetChildren().end(); ++i) {
		Render(*(*i));
	}
}

void	Renderer::UpdateScene(float msec) {
	time += msec;

	for (int i = 0; i < renderObjects.size(); i++) {
		(renderObjects[i]->Update(msec));
	}
	// *************** SCENE MOVEMENT / TEXTURE CHANGE ******************
	// enables you to move the camera around the scene with the defined keys
	if (Keyboard::KeyDown(KEY_A)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(-0.1f * 5, 0, 0));
	};

	if (Keyboard::KeyDown(KEY_D)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.1f * 5, 0, 0));
	}
	if (Keyboard::KeyDown(KEY_W)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.1f * 5, 0));
	}
	if (Keyboard::KeyDown(KEY_S)) {
		viewMatrix = viewMatrix * 
			Matrix4::Translation(Vector3(0.0, -0.1f * 5, 0));
	}

	if (Keyboard::KeyDown(KEY_E)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, 0.1 * 5));
	}
	if (Keyboard::KeyDown(KEY_C)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, -0.1 * 5));
	}
}

GLuint Renderer::LoadTexture(char* filename, bool textureRepeating){
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
		return texture;	   
	}					   
}						   