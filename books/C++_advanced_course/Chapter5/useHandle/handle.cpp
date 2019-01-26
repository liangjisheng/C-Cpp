
#include "handle.h"


class handle::wrapped
{
public:
	int i;
};

void handle::create()
{
	working = new wrapped;
	working->i = 5;
}

int handle::read() { return working->i; }

void handle::change(int n) { working->i = n; }

void handle::destory()
{
	delete working;
	working = 0;
}

handle::handle() { create(); }

handle::~handle() { destory(); }
