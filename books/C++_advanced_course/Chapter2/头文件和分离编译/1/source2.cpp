
#include <iostream>

class A
{
	int num;
public:
	A() { num = 5; }
	void show();
};

void see(A&);			// ����source1�ж���ĺ���

int main()
{
	A a;
	see(a);

	system("pause");
	return 0;
}