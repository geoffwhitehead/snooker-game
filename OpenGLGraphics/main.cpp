#include "Renderer.h"
#include "RenderObject.h"
#include <cmath>
#pragma comment(lib, "nclgl.lib")

const float Z = 10.f; // something random for now
const float MAX_VEL = 10.0f; // maximum speed
const float X_BOUND = 20.0f - 1;
const float Y_BOUND = 20.0f - 1;
const float GAME_DEPTH = -20.0f;
const float MAX_VELOCITY = 1.5f;
const float SNOOKER_WIDTH = 360.0f;
const float SNOOKER_HEIGHT = 180.0f;
const float TABLE_BORDER = 50.0f;
const float CUSHION_WIDTH = 18.0f;
const float POCKET_WIDTH = 63.0f;


vector<Entity*> entityObjects;

void	AddEntityObject(Entity *e){
	entityObjects.push_back(e);
}


void main(void) {
	Window w = Window(1024, 768);
	Renderer r(w);

	//SHADERS
	Shader* shader_basic = new Shader("./shaders/basicVert.glsl", "./shaders/basicFrag.glsl");
	Shader* shader_simple = new Shader("./shaders/textureVert.glsl", "./shaders/textureFrag.glsl");

	//MESHES
	Mesh* mesh_triangle = Mesh::GenerateTriangle();
	Mesh* mesh_circle = Mesh::GenerateTriFan();
	Mesh* mesh_hollowCircle = Mesh::GenerateTriFanBorder();
	Mesh* mesh_bgMesh = Mesh::GeneratePoints(1);
	Mesh* mesh_tessMesh = Mesh::GenerateQuadPatch();
	Mesh* mesh_quad = Mesh::GenerateQuad();

	//TEXTURES
	
	GLuint tex_table = r.LoadTexture("./textures/snooker_table.png");

	//glUniform1f(c1.SetColour(), RED);

	Entity* tbl_left = new Entity("table_left", Vector3(-SNOOKER_WIDTH / 2 + CUSHION_WIDTH, 0, 0), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	Entity* tbl_right = new Entity("table_right", Vector3(SNOOKER_WIDTH / 2 - CUSHION_WIDTH, 0, 0), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	Entity* tbl_bottom = new Entity("table_bottom", Vector3(0, -SNOOKER_HEIGHT / 2 + CUSHION_WIDTH, 0), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	Entity* tbl_top = new Entity("table_top", Vector3(0, SNOOKER_HEIGHT / 2 - CUSHION_WIDTH, 0), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_quad, shader_basic);
	Entity* table = new Entity("table", Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), mesh_quad, shader_simple, tex_table);
	
	table->scale(Vector3(SNOOKER_WIDTH, SNOOKER_HEIGHT, 1));
	tbl_left->scale(Vector3(3, SNOOKER_HEIGHT - POCKET_WIDTH, 1));
	tbl_right->scale(Vector3(3, SNOOKER_HEIGHT - POCKET_WIDTH, 1));
	tbl_bottom->scale(Vector3(SNOOKER_WIDTH - POCKET_WIDTH, 3, 1));
	tbl_top->scale(Vector3(SNOOKER_WIDTH - POCKET_WIDTH, 3, 1));
	
	AddEntityObject(new Entity("red1", Vector3(75.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red2", Vector3(3.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red2", Vector3(3.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red3", Vector3(5.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red4", Vector3(7.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red5", Vector3(9.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red6", Vector3(11.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red7", Vector3(13.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red8", Vector3(15.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red9", Vector3(350.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red10", Vector3(19.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red11", Vector3(21.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red12", Vector3(23.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red13", Vector3(25.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red14", Vector3(27.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("red15", Vector3(29.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));

	AddEntityObject(new Entity("green", Vector3(39.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("yellow", Vector3(31.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("blue", Vector3(33.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("pink", Vector3(35.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("black", Vector3(37.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("brown", Vector3(39.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	AddEntityObject(new Entity("white", Vector3(39.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));

	
	AddEntityObject(tbl_left);
	AddEntityObject(tbl_right);
	AddEntityObject(tbl_bottom);
	AddEntityObject(tbl_top);

	AddEntityObject(table);

	// add render objects
	for (int i = 0; i < entityObjects.size(); i++)
	{
		r.AddRenderObject(*entityObjects[i]->getRenderObject());
	}
	
	while(w.UpdateWindow()) {
		
		float msec = w.GetTimer()->GetTimedMS();

		r.UpdateScene(msec);

		r.ClearBuffers();
		r.RenderScene();
		r.SwapBuffers();
	}
	
}