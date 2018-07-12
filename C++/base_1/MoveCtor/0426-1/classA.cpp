
#include <iostream>
#include "classA.h"

classA::classA(int n /* = 0 */, double d /* = 0.0 */)
	: m_n(n), m_d(d)
{
	std::cout << "classA ctor" << std::endl;
}

classA::classA(const classA& src)
{
	std::cout << "classA copy ctor" << std::endl;
	m_n = src.m_n;
	m_d = src.m_d;
}

classA::~classA() { std::cout << "classA destructor" << std::endl; }

void classA::show() const
{
	std::cout << "Integer: " << m_n << " " << "double: " << m_d << std::endl;
}