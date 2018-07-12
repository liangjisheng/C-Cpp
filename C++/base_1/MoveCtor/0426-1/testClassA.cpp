
#include <iostream>
#include "classA.h"

static void func(classA objA)
{
	std::cout << &objA << std::endl;
	objA.show();
}

static classA func1()
{
	classA obj(1, 2.0);
	return obj;
}

void testClassA()
{
	std::cout << std::endl;
	classA obj(1, 1.1);
	std::cout << &obj << std::endl;
	func(obj);
	std::cout << std::endl;

	classA obj1(func1());
	obj1.show();
	std::cout << std::endl;
}
