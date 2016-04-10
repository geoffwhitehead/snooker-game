#pragma once
class SystemManager
{
public:
	SystemManager();
	virtual ~SystemManager();
	virtual void update(float) = 0;
	virtual void destroy() = 0;
	virtual void init() = 0;
	virtual void addSubSystem() = 0;
};

