
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
	// NULL�Ǻ꣬�������������
	// nullptr�������Ŀ�ָ��
	Test t;
	t.TestWork(NULL);
	t.TestWork(nullptr);

	system("pause");
	return 0;
}