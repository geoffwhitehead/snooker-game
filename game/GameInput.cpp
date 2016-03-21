#include "GameInput.h"


GameInput::GameInput(GameManager* gm)
{
	this->gm = gm;
}

void GameInput::init() {

}

GameInput::~GameInput()
{
}

void GameInput::update(float msec) {
	if (Mouse::ButtonDown(MouseButtons(MOUSE_LEFT))) {
		Vector3 pos = Vector3(this->gm->getWindow()->GetOSMousePosition().x, this->gm->getWindow()->GetOSMousePosition().y, 0.0);
		cout << pos;
		cout << "length: " << pos.Length();
	}
	
	vector<Entity*>* e = gm->getEntities();

	Entity* white = (*e)[0]->getChildren()[0];

	if (Keyboard::KeyDown(KEY_Z))
		white->setVel(Vector3(0.031f, 0.0007f, 0.0f));

	Vector2 mPos = this->gm->getWindow()->GetOSMousePosition();

	white->getPhysicsObject()->setPos(Vector3(mPos.x, mPos.y, 0.0f));
}

void GameInput::destroy() {

}
