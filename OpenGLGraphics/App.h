#pragma once
#include "Entity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class App
{
public:
	App();
	~App();
	std::vector<Entity> run(float, float);
	static float getRandom(float);
	void print(std::vector<Entity>);
	void checkRange(std::vector<Entity>&);
};

