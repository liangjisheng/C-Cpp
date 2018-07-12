
#include <iostream>
#include "classC.h"

classC::classC(int n /* = 0 */, double d /* = 0.0 */, const char *p /* = NULL */)
	: m_n(n), m_d(d)
{
	std::cout << "classC ctor" << std::endl;
	if (p != NULL)
	{
		m_p = new char[strlen(p) + 1];
		memset(m_p, 0, strlen(p) + 1);
		memcpy(m_p, p, strlen(p));
	}
}

classC::classC(const classC& src)
{
	std::cout << "classC copy ctor" << std::endl;
	m_n = src.m_n;
	m_d = src.m_d;
	m_p = new char[strlen(src.m_p) + 1];
	memset(m_p, 0, strlen(src.m_p) + 1);
	memcpy(m_p, src.m_p, strlen(src.m_p));
}

classC& classC::operator=(const classC& src)
{
	std::cout << "classC assign operator" << std::endl;
	if (this == &src)
		return *this;

	m_n = src.m_n;
	m_d = src.m_d;
	if (m_p != NULL)
	{
		delete [] m_p;
		m_p = NULL;
	}

	m_p = new char[strlen(src.m_p) + 1];
	memset(m_p, 0, strlen(src.m_p) + 1);
	memcpy(m_p, src.m_p, strlen(src.m_p));

	return *this;
}

classC::~classC() 
{ 
	std::cout << "classC destructor" << std::endl;
	if (m_p != NULL)
	{
		delete [] m_p;
		m_p = NULL;
	}
}

void classC::show() const
{
	std::cout << "Integer: " << m_n << " " << "double: " << m_d << std::endl;
	if (m_p != NULL)
		std::cout << "char: " << m_p << std::endl;
}

const char* classC::GetP() const { return m_p; }
