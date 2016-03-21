#include "GameInput.h"


GameInput::GameInput(GameManager* gm, Camera * cam)
{
	this->gm = gm;
	this->cam = cam;
}

void GameInput::init() {

}

GameInput::~GameInput()
{
}

void GameInput::update(float msec) {
	if (Mouse::ButtonDown(MouseButtons(MOUSE_LEFT))) {
		//Vector3 pos = Vector3(this->gm->getWindow()->GetOSMousePosition().x, this->gm->getWindow()->GetOSMousePosition().y, -400.0);
		//cout << pos << endl;
		//cout << "length: " << pos.Length() << endl;
	//	cout << cam->UnProject(pos, 1024.0f / 768.0f, 45.0f) << endl << endl << endl;
		cout << "HERE" << this->gm->getWindow()->convertToScreenCoords(this->gm->getWindow()->GetOSMousePosition());

		vector<Entity*>* e = gm->getEntities();

		Entity* white = (*e)[0]->getChildren()[0];
		Vector2 pos = gm->getWindow()->GetOSMousePosition();
		cout << pos << endl;
		Vector2 mPos = gm->getWindow()->convertToScreenCoords(pos);
		Vector3 mPos3D = Vector3(mPos.x, mPos.y, 5.0f);
		//white->getPhysicsObject()->setPos(Vector3(mPos.x, mPos.y, 5.0f));

		Vector3 cueBall = white->getPhysicsObject()->getPos();
		Vector3 dir = mPos3D - cueBall;
		white->setVel(dir/100);

	}
	
	

	//if (Keyboard::KeyDown(KEY_Z))
	//	white->setVel(Vector3(0.031f, 0.0007f, 0.0f));

	
}

void GameInput::destroy() {

}
