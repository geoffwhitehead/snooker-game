#pragma once
#include "../engine-base/SubSystem.h"
#include <vector>

using namespace std;

class InputManager :
	public SubSystem
{
public:
	

	InputManager();
	~InputManager();
	void update(float);
	void destroy();
	void init();

	vector<SubSystem*> sub_systems;
};

