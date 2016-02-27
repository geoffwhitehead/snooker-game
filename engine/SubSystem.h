#pragma once
class SubSystem
{
public:
	SubSystem();
	virtual ~SubSystem();
	virtual void update() = 0;
	virtual void destroy() = 0;
};

