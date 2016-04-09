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

		vector<Entity*>* e = gm->getEntities();
		Entity* white = (*e)[0]->getChildren()[0];

		cout << (*e)[0]->getChildren()[0]->getPhysicsObject()->getPos();

		Vector2 pos = gm->getWindow()->GetOSMousePosition();
		Vector2 mPos = gm->getWindow()->convertToScreenCoords(pos);
		Vector3 mPos3D = Vector3(mPos.x, mPos.y, 5.0f);
		Vector3 cueBall = white->getPhysicsObject()->getPos();

		// apply vector to cue ball
		Vector3 dir = mPos3D - cueBall;
		white->setVel(dir/100);

	}
	

	
}

void GameInput::destroy() {

}
