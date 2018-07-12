
#include <iostream>

class Engine
{
public:
	virtual void start();
};

void Engine::start()
{
	std::cout << "starting Engine\n";
}

class FordTaurus
{
public:
	virtual void start();
protected:
	Engine engine_;		// An Engine is part of a FordTaurus
};

void FordTaurus::start()
{
	std::cout << "starting FordTaurus\n";
	engine_.start();
}

void test_part_of()
{
	FordTaurus taurus;
	taurus.start();
}
