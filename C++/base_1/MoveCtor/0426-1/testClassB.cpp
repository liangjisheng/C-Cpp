
#include <iostream>
#include <iomanip>
#include "classB.h"

static void func2(classB objB)
{
	std::cout << &objB << std::endl;
	objB.show();
}

static classB func3()
{
	classB obj(1, 1.1, "in func");
	std::cout << &obj << std::endl;
	std::cout << "0x" << std::setw(8) << std::setfill('0') 
		<< std::hex << reinterpret_cast<unsigned int>(obj.GetP()) << std::endl;
	std::cout << obj.GetAddressN() << std::endl;
	return obj;
}

void testClassB()
{
	std::cout << std::endl;
	classB objB(1, 1.2, "objB");
	std::cout << &objB << std::endl;
	func2(objB);
	std::cout << std::endl;

	classB objB1(func3());
	std::cout << &objB1 << std::endl;
	std::cout << "0x" << std::setw(8) << std::setfill('0') << std::hex 
		<< reinterpret_cast<unsigned int>(objB1.GetP()) << std::endl;
	std::cout << objB1.GetAddressN() << std::endl;
	objB1.show();
	std::cout << std::endl;
}
