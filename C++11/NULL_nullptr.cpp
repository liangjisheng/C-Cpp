
#include<iostream>

using std::cout;
using std::endl;

class Test
{
public:
	void TestWork(int index) { cout << "TestWork1" << endl; }
	void TestWork(int *index) { cout << "TestWork2" << endl; }
};

int main()
{
	// NULL是宏，用整数来定义的
	// nullptr是真正的空指针
	Test t;
	t.TestWork(NULL);
	t.TestWork(nullptr);

	system("pause");
	return 0;
}