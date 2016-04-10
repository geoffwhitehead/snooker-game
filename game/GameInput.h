#pragma once
#include "../engine-base/SubSystem.h"
#include "../engine-base/GameManager.h"
#include "../nclgl/Window.h"
#include "../engine-base/Camera.h"
#include <assert.h>     /* assert */

#define FORCE_SCALE 120

class GameInput : public SubSystem
{
public:
	GameInput(GameManager* gm, Camera* cam);
	~GameInput();
	void init();
	void update(float msec);
	void destroy();
	GameManager* gm;
	Camera * cam;
};

