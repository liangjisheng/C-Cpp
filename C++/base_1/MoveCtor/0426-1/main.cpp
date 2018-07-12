
#include <iostream>

#ifdef _DEBUG
	#include <vld.h>
#endif

void testClassA();
void testClassB();
void testClassC();

int main()
{
	//const char *p = "test";
	//unsigned int uip = reinterpret_cast<unsigned int>(p);
	//cout << "0x" << std::setw(8) << std::setfill('0') << std::hex << uip << endl;
	testClassA();
	testClassB();
	testClassC();

	system("pause");
	return 0;
}

