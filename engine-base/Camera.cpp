#include "Camera.h"

/*
Polls the camera for keyboard / mouse movement.
Should be done once per frame! Pass it the msec since
last frame (default value is for simplicities sake...)
*/


Matrix4 Camera::viewMatrix;
Matrix4 Camera::projMatrix;


void Camera::destroy() {};

void Camera::update(float msec)	{
	//Update the mouse by how much
	pitch -= (Mouse::GetRelativePosition().y);
	yaw	  -= (Mouse::GetRelativePosition().x);

	//Bounds check the pitch, to be between straight up and straight down ;)
	pitch = min(pitch,90.0f);
	pitch = max(pitch,-90.0f);

	if(yaw <0) {
		yaw+= 360.0f;
	}
	if(yaw > 360.0f) {
		yaw -= 360.0f;
	}

	msec *= 2.0f;

	if (Keyboard::KeyDown(KEY_W)) position += Matrix4::Rotation(yaw, Vector3(0, 1, 0)) * Vector3(0, 0, -1) * msec*0.2;
	if (Keyboard::KeyDown(KEY_S)) position -= Matrix4::Rotation(yaw, Vector3(0, 1, 0)) * Vector3(0, 0, -1) * msec*0.2;

	if (Keyboard::KeyDown(KEY_A)) position += Matrix4::Rotation(yaw, Vector3(0,1,0)) * Vector3(-1,0,0) * msec*0.2;
	if (Keyboard::KeyDown(KEY_D)) position -= Matrix4::Rotation(yaw, Vector3(0,1,0)) * Vector3(-1,0,0) * msec*0.2;

	if (Keyboard::KeyDown(KEY_SHIFT)) position.y += msec*0.2;
	if (Keyboard::KeyDown(KEY_SPACE)) position.y -= msec*0.2;
	this->viewMatrix = this->BuildViewMatrix();
}


/*
Generates a view matrix for the camera's viewpoint. This matrix can be sent
straight to the shader...it's already an 'inverse camera' matrix.
*/
Matrix4 Camera::BuildViewMatrix()	{
	//Why do a complicated matrix inversion, when we can just generate the matrix
	//using the negative values ;). The matrix multiplication order is important!
	return	Matrix4::Rotation(-pitch, Vector3(1,0,0)) * 
			Matrix4::Rotation(-yaw, Vector3(0,1,0)) * 
			Matrix4::Translation(-position);
};