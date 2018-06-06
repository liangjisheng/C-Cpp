
#include <iostream>

using std::cout;
using std::endl;


void test_1()
{
	bool bvar = false;
	int i = 5, j = 5;
	bvar = i == j;
	cout << bvar << endl;
	// bvar将会当做整数1来对待
	cout << bvar + i << endl;

	// 如果显示的将一个整型变量的值赋给布尔变量，编译器会给出一个警告，
	// 并且一定要清楚bool变量的值只能是0或1
	bvar = i;
}


int main()
{
	test_1();

	system("pause");
	return 0;
}