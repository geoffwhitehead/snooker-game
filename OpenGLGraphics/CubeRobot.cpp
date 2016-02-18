#include "CubeRobot.h"

/*
CubeRobot::CubeRobot()
{
	Mesh*headMesh = Mesh::LoadMeshFile("robotHead.mesh");
	Mesh*bodyMesh = Mesh::LoadMeshFile("robotBody.mesh");
	Mesh*limbsMesh = Mesh::LoadMeshFile("robotLimbs.mesh");

	Shader* basicShader = new Shader("basicVert.glsl", "basicFrag.glsl");

	RenderObject *body = new RenderObject(bodyMesh, basicShader);
	body->SetTransform(Matrix4::Translation(Vector3(0, 35, 0)));
	AddChild(body);

	RenderObject *head = new RenderObject(cube, basicShader);
	head->SetTransform(Matrix4::Translation(Vector3(0, 30, 0)));
	AddChild(head);

	RenderObject *leftArm = new RenderObject(cube, basicShader);
	leftArm->SetTransform(Matrix4::Translation(Vector3(-12, 30, -1)));
	AddChild(leftArm);

	RenderObject *rightArm = new RenderObject(cube, basicShader);
	rightArm->SetTransform(Matrix4::Translation(Vector3(12, 30, -1)));
	AddChild(rightArm);

	RenderObject *leftLeg = new RenderObject(cube, basicShader);
	leftLeg->SetTransform(Matrix4::Translation(Vector3(-8, 0, 0)));
	AddChild(leftLeg);

	RenderObject *rightLeg = new RenderObject(cube, basicShader);
	rightLeg->SetTransform(Matrix4::Translation(Vector3(8, 0, 0)));
	AddChild(rightLeg);
	

}

void CubeRobot::Update(float msec){
	MatrixMode = modelMatrix * Matrix4::Rotation(msec / 10.0f, Vector3(0, 1, 0));

	children[1]->SetTransform(children[1]->GetTransform() * Matrix4::Rotation(-msec / 10.0f, Vector3(0, 1, 0)));
	
	children[2]->SetTransform(children[2]->GetTransform() * Matrix4::Rotation(-msec / 10.0f, Vector3(1, 0, 0)));

	children[3]->SetTransform(children[3]->GetTransform() * Matrix4::Rotation(-msec / 10.0f, Vector3(1, 0, 0)));

	SceneNode::Update(msec);
}
  
CubeRobot::~CubeRobot()
{
}
*/