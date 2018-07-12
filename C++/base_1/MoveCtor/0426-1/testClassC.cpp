
#include <iostream>
#include <iomanip>
#include "classC.h"

static classC func4()
{
	classC obj(1, 1.1, "in func4");
	std::cout << &obj << std::endl;
	std::cout << "0x" << std::setw(8) << std::setfill('0') 
		<< std::hex << reinterpret_cast<unsigned int>(obj.GetP()) << std::endl;
	return obj;
}

void testClassC()
{
	std::cout << std::endl;
	classC objC(func4());
	std::cout << &objC << std::endl;
	std::cout << "0x" << std::setw(8) << std::setfill('0') 
		<< std::hex << reinterpret_cast<unsigned int>(objC.GetP()) << std::endl;
	objC.show();
	std::cout << std::endl;
}
