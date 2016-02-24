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
	basicShader = new Shader("./shaders/basicVert.glsl", "./shaders/basicFrag.glsl");
	simpleShader = new Shader("./shaders/textureVert.glsl", "./shaders/textureFrag.glsl");

	//MESHES
	triangle = Mesh::GenerateTriangle();
	triFanMesh = Mesh::GenerateTriFan();
	triLoopMesh = Mesh::GenerateTriFanBorder();
	bgMesh = Mesh::GeneratePoints(1);
	tessMesh = Mesh::GenerateQuadPatch();
	quadMesh = Mesh::GenerateQuad();

	//TEXTURES
	tableTex = LoadTexture("./textures/snooker_table.png");

	//RENDER OBJECTS

	tf1 = RenderObject(triFanMesh, basicShader);
	tf2 = RenderObject(triFanMesh, basicShader);
	tf3 = RenderObject(triFanMesh, basicShader);


	tbl_top = RenderObject(quadMesh, basicShader);
	tbl_right = RenderObject(quadMesh, basicShader);
	tbl_bottom = RenderObject(quadMesh, basicShader);
	tbl_left = RenderObject(quadMesh, basicShader);
	obj_Table = RenderObject(quadMesh, simpleShader, tableTex);

	AddRenderObject(c1);
	glUniform1f(c1.SetColour(), RED);
	AddRenderObject(c2);
	AddRenderObject(c3);
	AddRenderObject(tf1);
	AddRenderObject(tl1);
	AddRenderObject(tf2);
	AddRenderObject(tl2);
	AddRenderObject(tf3);
	AddRenderObject(tl3);
	AddRenderObject(tbl_top);
	AddRenderObject(tbl_right);
	AddRenderObject(tbl_bottom);
	AddRenderObject(tbl_left);
	AddRenderObject(obj_Table);

	/*
	//ENTITIES
	circle1 = new Entity(2, 2, -10, 0, 0, 0, 0, &(c1));
	circle2 = new Entity(3, 3, -20, 0, 0, 0, 0, &(c2));
	circle3 = new Entity(4, 4, -30, 0, 0, 0, 0, &(c3));
	triFan1 = new Entity(getRandom(X_BOUND), getRandom(Y_BOUND), GAME_DEPTH, 3, getRandom(5), getRandom(5), 0, &(tf1));
	triLoop1 = new Entity(triFan1->getPos().x, triFan1->getPos().y, triFan1->getPos().z, triFan1->getAggroRange(), triFan1->getDir().x, triFan1->getDir().y, 0, &(tl1));
	triFan2 = new Entity(getRandom(X_BOUND), getRandom(Y_BOUND), GAME_DEPTH, 3, getRandom(5), getRandom(5), 0, &(tf2));
	triLoop2 = new Entity(triFan2->getPos().x, triFan2->getPos().y, triFan2->getPos().z, triFan2->getAggroRange(), triFan2->getDir().x, triFan2->getDir().y, 0, &(tl2));
	triFan3 = new Entity(getRandom(X_BOUND), getRandom(Y_BOUND), GAME_DEPTH, 3, getRandom(5), getRandom(5), 0, &(tf3));
	triLoop3 = new Entity(triFan3->getPos().x, triFan3->getPos().y, triFan3->getPos().z, triFan3->getAggroRange(), triFan3->getDir().x, triFan3->getDir().y, 0, &(tl3));

	tableTop = new Entity(10, 20, GAME_DEPTH, 0, 0, 0, 0, &(tbl_top));
	tableRight = new Entity(20, 10, GAME_DEPTH, 0, 0, 0, 0, &(tbl_right));
	tableBottom = new Entity(10, 0, GAME_DEPTH, 0, 0, 0, 0, &(tbl_bottom));
	tableLeft = new Entity(0, 10, GAME_DEPTH, 0, 0, 0, 0, &(tbl_left));
	*/

	//POSITION TRANSFORMS
	
	
	// SCALE TRANSFORMS
	tbl_top.SetModelMatrix(Matrix4::Translation(Vector3(0, SNOOKER_HEIGHT / 2 - CUSHION_WIDTH, 0)) * Matrix4::Scale(Vector3(SNOOKER_WIDTH - POCKET_WIDTH, 3, 1)));
	tbl_right.SetModelMatrix(Matrix4::Translation(Vector3(SNOOKER_WIDTH / 2 - CUSHION_WIDTH, 0, 0)) * Matrix4::Scale(Vector3(3, SNOOKER_HEIGHT - POCKET_WIDTH, 1)));
	tbl_bottom.SetModelMatrix(Matrix4::Translation(Vector3(0, -SNOOKER_HEIGHT / 2 + CUSHION_WIDTH, 0)) * Matrix4::Scale(Vector3(SNOOKER_WIDTH - POCKET_WIDTH, 3, 1)));
	tbl_left.SetModelMatrix(Matrix4::Translation(Vector3(-SNOOKER_WIDTH / 2 + CUSHION_WIDTH, 0, 0)) * Matrix4::Scale(Vector3(3, SNOOKER_HEIGHT - POCKET_WIDTH, 1)));

	obj_Table.SetModelMatrix(obj_Table.GetModelMatrix() * (Matrix4::Scale(Vector3(SNOOKER_WIDTH, SNOOKER_HEIGHT, 1))));


	/*
	//ADD
	AddEntityObject(circle1);
	AddEntityObject(circle2);
	AddEntityObject(circle3);
	AddEntityObject(triFan1);
	AddEntityObject(triLoop1);
	AddEntityObject(triFan2);
	AddEntityObject(triLoop2);
	AddEntityObject(triFan3);
	AddEntityObject(triLoop3);
	AddEntityObject(tableTop);
	AddEntityObject(tableRight);
	AddEntityObject(tableBottom);
	AddEntityObject(tableLeft);
	*/
	
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