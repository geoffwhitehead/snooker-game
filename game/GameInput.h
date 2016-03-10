#pragma once

#include "../nclgl/Window.h"
#include "../nclgl/Matrix4.h"
#include "../nclgl/Vector3.h"
#include "SubSystem.h"

#include "../engine-base/SubSystem.h"




class GameInput : public SubSystem
{

public:
	static Matrix4 viewMatrix;
	static Matrix4 projMatrix;
	
	void GameInput::init(){};

	GameInput(void){
		yaw = 0.0f;
		pitch = 0.0f;
		GameInput::projMatrix = Matrix4::Perspective(1, 1000, 1024.0f / 768.0f, 45);
		GameInput::viewMatrix = this->BuildViewMatrix();
	};

	GameInput(float pitch, float yaw, Vector3 position){
		this->pitch = pitch;
		this->yaw = yaw;
		this->position = position;
		GameInput::projMatrix = Matrix4::Perspective(1, 1000, 1024.0f / 768.0f, 45);
		GameInput::viewMatrix = this->BuildViewMatrix();
	};

	~GameInput(void){};
	GameInput();
	~GameInput();
	void init();
	void update(float msec);
	void destroy();

	static Matrix4 viewMatrix;
	static Matrix4 projMatrix;

	void GameInput::init(){};

	GameInput(void){
		yaw = 0.0f;
		pitch = 0.0f;
	};

	GameInput(float pitch, float yaw, Vector3 position){
		this->pitch = pitch;
		this->yaw = yaw;
		this->position = position;
	}

	~GameInput(void){};

	void update(float msec = 10.0f);

	void destroy();

	//Builds a view matrix for the current camera variables, suitable for sending straight
	//to a vertex shader (i.e it's already an 'inverse camera matrix').
	Matrix4 BuildViewMatrix();

	//Gets position in world space
	Vector3 GetPosition() const { return position; }
	//Sets position in world space
	void	SetPosition(Vector3 val) { position = val; }

	//Gets yaw, in degrees
	float	GetYaw()   const { return yaw; }
	//Sets yaw, in degrees
	void	SetYaw(float y) { yaw = y; }

	//Gets pitch, in degrees
	float	GetPitch() const { return pitch; }
	//Sets pitch, in degrees
	void	SetPitch(float p) { pitch = p; }


protected:
	float	yaw;
	float	pitch;
	Vector3 position;
};



};

