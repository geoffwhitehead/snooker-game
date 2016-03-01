#include "../engine/Camera.h"
#include "../engine/GameManager.h"
#include "../nclgl/OGLRenderer.h"
#include "GameInput.h"

#define W_X 1024.0f
#define W_Y 768.0f

#define Z 10.f; // something random for now
#define MAX_VEL 10.0f; // maximum speed
#define X_BOUND 20.0f - 1
#define Y_BOUND 20.0f - 1
#define GAME_DEPTH -20.0f
#define MAX_VELOCITY 1.5f
#define CUSHION_WIDTH 18.0f
#define POCKET_WIDTH 63.0f
#define SNOOKER_WIDTH 356.87f
#define HALF_WIDTH SNOOKER_WIDTH /2
#define HALF_HEIGHT SNOOKER_HEIGHT /2
#define SNOOKER_HEIGHT 177.8f
#define TABLE_BORDER 50.0f
#define TABLE_POS Vector3(0.0f, 0.0f, -7.5f)

#define BALL_RADIUS 2.6f
#define BALL_WIDTH 5.2f
const float ball_offset = sqrt(pow(BALL_WIDTH, 2.0) + (pow(BALL_RADIUS, 2.0))) - 1.1;
#define BALL_Z 5.0f
#define M_BAULK_TO_CUSHION -HALF_WIDTH + 73.66f
#define M_SEMI_RADIUS 29.21f

#define POS_BLUE Vector3(0.0f, 0.0f, BALL_Z)
#define POS_PINK Vector3(HALF_WIDTH - 89.75, 0.0f, BALL_Z)
#define POS_BLACK Vector3(HALF_WIDTH - 31.75f, 0.0f, BALL_Z)
#define POS_BROWN Vector3(M_BAULK_TO_CUSHION, 0.0f, BALL_Z) 
#define POS_YELLOW Vector3(M_BAULK_TO_CUSHION, -M_SEMI_RADIUS, BALL_Z)
#define POS_GREEN Vector3(M_BAULK_TO_CUSHION, M_SEMI_RADIUS, BALL_Z)
#define POS_WHITE Vector3(M_BAULK_TO_CUSHION - 10.0f, 10.0f, BALL_Z)

#define RED_TOP 100.0f
#define POS_RED01 Vector3(RED_TOP, 0, BALL_Z)
//row1
#define POS_RED02 Vector3(RED_TOP + ball_offset, BALL_RADIUS, BALL_Z)
#define POS_RED03 Vector3(RED_TOP + ball_offset, -BALL_RADIUS, BALL_Z)
//row2
#define POS_RED04 Vector3(RED_TOP + ball_offset*2, BALL_WIDTH, BALL_Z)
#define POS_RED05 Vector3(RED_TOP + ball_offset*2, 0, BALL_Z)
#define POS_RED06 Vector3(RED_TOP + ball_offset*2, -BALL_WIDTH, BALL_Z)
//row3
#define POS_RED07 Vector3(RED_TOP + ball_offset*3, BALL_RADIUS + BALL_WIDTH, BALL_Z)
#define POS_RED08 Vector3(RED_TOP + ball_offset*3, BALL_RADIUS, BALL_Z)
#define POS_RED09 Vector3(RED_TOP + ball_offset*3, -BALL_RADIUS, BALL_Z)
#define POS_RED10 Vector3(RED_TOP + ball_offset*3, -BALL_RADIUS + -BALL_WIDTH, BALL_Z)
//row4
#define POS_RED11 Vector3(RED_TOP + ball_offset*4, BALL_WIDTH*2, BALL_Z)
#define POS_RED12 Vector3(RED_TOP + ball_offset*4, BALL_WIDTH, BALL_Z)
#define POS_RED13 Vector3(RED_TOP + ball_offset*4, 0, BALL_Z)
#define POS_RED14 Vector3(RED_TOP + ball_offset*4, -BALL_WIDTH, BALL_Z)
#define POS_RED15 Vector3(RED_TOP + ball_offset*4, -BALL_WIDTH*2, BALL_Z)

#define VEC_ZERO Vector3(0.0f,0.0f,0.0f)

#define RED Vector4(1.0f, 0.0f, 0.0f, 0.7f)
#define GREEN Vector4(0.0f, 1.0f, 0.0f, 0.7f)
#define BROWN Vector4(0.4f, 0.2f, 0.0f, 0.7f)
#define YELLOW Vector4(1.0f, 1.0f, 0.0f, 0.7f)
#define BLUE Vector4(0.0f, 0.0f, 1.0f, 0.7f)
#define PINK Vector4(1.0f, 0.4f, 1.0f, 0.7f)
#define BLACK Vector4(0.0f, 0.0f, 0.0f, 0.7f)
#define WHITE Vector4(1.0f, 1.0f, 1.0f, 0.7f)

void main(void) {

	//CREATE SUB SYSTEMS

	
	Camera* camera = new Camera(0.0f, 0.0f, Vector3(0, 0, 400));
	GameInput* gi = new GameInput();
	Camera::projMatrix = Matrix4::Perspective(1, 1000, 1024.0f / 768.0f, 45);
	Camera::viewMatrix = camera->BuildViewMatrix();


	// GAME MANAGER
	GameManager *gm = new GameManager(W_X, W_Y);

	//SHADERS
	Shader* shader_basic = new Shader("./shaders/basicVert.glsl", "./shaders/basicFrag.glsl");
	Shader* shader_simple = new Shader("./shaders/textureVert.glsl", "./shaders/textureFrag.glsl");
	
	//TEXTURES
	GLuint tex_table = gm->LoadTexture("./textures/cloth.png");

	//MESHES
	Mesh* mesh_triangle = Mesh::GenerateTriangle();

	//Mesh* mesh_hollowCircle = Mesh::GenerateTriFanBorder();
	//Mesh* mesh_bgMesh = Mesh::GeneratePoints(1);
	//Mesh* mesh_tessMesh = Mesh::GenerateQuadPatch();
	Mesh* mesh_table = Mesh::GenerateQuad(SNOOKER_WIDTH, SNOOKER_HEIGHT);
	Mesh* mesh_tblLeft = Mesh::GenerateQuad(3, SNOOKER_HEIGHT - POCKET_WIDTH);
	Mesh* mesh_tblRight = Mesh::GenerateQuad(3, SNOOKER_HEIGHT - POCKET_WIDTH);
	Mesh* mesh_tblBottom = Mesh::GenerateQuad(SNOOKER_WIDTH - POCKET_WIDTH, 3);
	Mesh* mesh_tblTop = Mesh::GenerateQuad(SNOOKER_WIDTH - POCKET_WIDTH, 3);

	Mesh* mesh_redBall = Mesh::GenerateTriFan(BALL_RADIUS, RED);
	Mesh* mesh_greenBall = Mesh::GenerateTriFan(BALL_RADIUS, GREEN);
	Mesh* mesh_brownBall = Mesh::GenerateTriFan(BALL_RADIUS, BROWN);
	Mesh* mesh_yellowBall = Mesh::GenerateTriFan(BALL_RADIUS, YELLOW);
	Mesh* mesh_blueBall = Mesh::GenerateTriFan(BALL_RADIUS, BLUE);
	Mesh* mesh_pinkBall = Mesh::GenerateTriFan(BALL_RADIUS, PINK);
	Mesh* mesh_blackBall = Mesh::GenerateTriFan(BALL_RADIUS, BLACK);
	Mesh* mesh_whiteBall = Mesh::GenerateTriFan(BALL_RADIUS, WHITE);

	//Mesh* a = Mesh::GenerateQuad(50000, 25000);
	
	//Entity* canvas = new Entity("a", Vector3(0, 1, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), a, shader_basic);
	//gm->addEntity(canvas);


	Entity* table = new Entity("table", TABLE_POS, VEC_ZERO, VEC_ZERO, mesh_table, shader_simple, tex_table);
	
	table->addChild(new Entity("red01", POS_RED01, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red02", POS_RED02, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red03", POS_RED03, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red04", POS_RED04, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red05", POS_RED05, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red06", POS_RED06, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red07", POS_RED07, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red08", POS_RED08, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red09", POS_RED09, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red10", POS_RED10, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red11", POS_RED11, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red12", POS_RED12, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red13", POS_RED13, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red14", POS_RED14, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("red15", POS_RED15, VEC_ZERO, VEC_ZERO, mesh_redBall, shader_basic));
	table->addChild(new Entity("green", POS_GREEN, VEC_ZERO, VEC_ZERO, mesh_greenBall, shader_basic));
	table->addChild(new Entity("yellow", POS_YELLOW, VEC_ZERO, VEC_ZERO, mesh_yellowBall, shader_basic));
	table->addChild(new Entity("blue", POS_BLUE, VEC_ZERO, VEC_ZERO, mesh_blueBall, shader_basic));
	table->addChild(new Entity("pink", POS_PINK, VEC_ZERO, VEC_ZERO, mesh_pinkBall, shader_basic));
	table->addChild(new Entity("black", POS_BLACK, VEC_ZERO, VEC_ZERO, mesh_blackBall, shader_basic));
	table->addChild(new Entity("brown", POS_BROWN, VEC_ZERO, VEC_ZERO, mesh_brownBall, shader_basic));
	table->addChild(new Entity("white", POS_WHITE, VEC_ZERO, VEC_ZERO, mesh_whiteBall, shader_basic));
	table->addChild(new Entity("table_l", Vector3(-HALF_WIDTH, 0, BALL_Z), VEC_ZERO, VEC_ZERO, mesh_tblLeft, shader_basic));
	table->addChild(new Entity("table_r", Vector3(HALF_WIDTH, 0, BALL_Z), VEC_ZERO, VEC_ZERO, mesh_tblRight, shader_basic));
	table->addChild(new Entity("table_b", Vector3(0, -HALF_HEIGHT, BALL_Z), VEC_ZERO, VEC_ZERO, mesh_tblBottom, shader_basic));
	table->addChild(new Entity("table_t", Vector3(0, HALF_HEIGHT, BALL_Z), VEC_ZERO, VEC_ZERO, mesh_tblTop, shader_basic));

	// register entities
	gm->addEntity(table);

	//register subsystems
	gm->addSubSystem(camera);

	gm->run();

}