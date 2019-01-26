
#include <iostream>

class A
{
	int num;
public:
	A() { num = 5; }
	void show();
};

void see(A&);			// 声明source1中定义的函数

int main()
{
	A a;
	see(a);

	system("pause");
	return 0;
}