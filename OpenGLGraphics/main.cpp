
#pragma comment(lib, "nclgl.lib")
#include "GameManager.h";


const float Z = 10.f; // something random for now
const float MAX_VEL = 10.0f; // maximum speed
const float X_BOUND = 20.0f - 1;
const float Y_BOUND = 20.0f - 1;
const float GAME_DEPTH = -20.0f;
const float MAX_VELOCITY = 1.5f;
const float CUSHION_WIDTH = 18.0f;
const float POCKET_WIDTH = 63.0f;
const float SNOOKER_WIDTH = 360.0f;
const float SNOOKER_HEIGHT = 180.0f;
const float TABLE_BORDER = 50.0f;




void main(void) {
	
	// GAME MANAGER
	GameManager *gm = new GameManager();

	//SHADERS
	Shader* shader_basic = new Shader("./shaders/basicVert.glsl", "./shaders/basicFrag.glsl");
	Shader* shader_simple = new Shader("./shaders/textureVert.glsl", "./shaders/textureFrag.glsl");

	//MESHES
	Mesh* mesh_triangle = Mesh::GenerateTriangle();
	Mesh* mesh_circle = Mesh::GenerateTriFan();
	Mesh* mesh_hollowCircle = Mesh::GenerateTriFanBorder();
	Mesh* mesh_bgMesh = Mesh::GeneratePoints(1);
	Mesh* mesh_tessMesh = Mesh::GenerateQuadPatch();
	Mesh* mesh_table = Mesh::GenerateQuad(SNOOKER_WIDTH, SNOOKER_HEIGHT);
	Mesh* mesh_tblLeft = Mesh::GenerateQuad(3, SNOOKER_HEIGHT - POCKET_WIDTH);
	Mesh* mesh_tblRight = Mesh::GenerateQuad(3, SNOOKER_HEIGHT - POCKET_WIDTH);
	Mesh* mesh_tblBottom = Mesh::GenerateQuad(SNOOKER_WIDTH - POCKET_WIDTH, 3);
	Mesh* mesh_tblTop = Mesh::GenerateQuad(SNOOKER_WIDTH - POCKET_WIDTH, 3);
	//Mesh* a = Mesh::GenerateQuad(50000, 25000);
	//TEXTURES

	GLuint tex_table = gm->LoadTexture("./textures/snooker_table.png");
 
	Entity* table = new Entity("table", Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), mesh_table, shader_simple, tex_table);
	//Entity* canvas = new Entity("a", Vector3(0, 1, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), a, shader_basic);
	//gm->addEntity(table);
	//gm->addEntity(canvas);

	gm->addEntity(new Entity("red1", Vector3(0.0f, 0.0f, -20.0f), Vector3(0.0001, 0.0001, 0), Vector3(0.00001, 0.00001, 0), mesh_circle, shader_basic));
	table->addChild(new Entity("red2", Vector3(3.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red2", Vector3(3.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red3", Vector3(5.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red4", Vector3(7.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red5", Vector3(9.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red6", Vector3(11.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red7", Vector3(13.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red8", Vector3(15.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red9", Vector3(350.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red10", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red11", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red12", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red13", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red14", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("red15", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("green", Vector3(0.0f, 0,0), Vector3(0,0,0), Vector3(0,0,0), mesh_circle, shader_basic));
	table->addChild(new Entity("yellow", Vector3(31.0f, 1.0f, 3.0f), Vector3(0,0,0), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	table->addChild(new Entity("blue", Vector3(0.0f, 1.0f, -13.0f), Vector3(0,0,0), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	table->addChild(new Entity("pink", Vector3(0.0f, 1.0f, 3.0f), Vector3(0,0,0), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	table->addChild(new Entity("black", Vector3(0.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	table->addChild(new Entity("brown", Vector3(0.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	table->addChild(new Entity("white", Vector3(0.0f, 1.0f, 3.0f), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_circle, shader_basic));
	table->addChild(new Entity("table_left", Vector3(-SNOOKER_WIDTH / 2 + CUSHION_WIDTH, 0, 3), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_tblLeft, shader_basic));
	table->addChild(new Entity("table_right", Vector3(SNOOKER_WIDTH / 2 - CUSHION_WIDTH, 0, 3), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_tblRight, shader_basic));
	table->addChild(new Entity("table_bottom", Vector3(0, -SNOOKER_HEIGHT / 2 + CUSHION_WIDTH, 3), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_tblBottom, shader_basic));
	table->addChild(new Entity("table_top", Vector3(0, SNOOKER_HEIGHT / 2 - CUSHION_WIDTH, 3), Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f), mesh_tblTop, shader_basic));
	

	gm->run();


}