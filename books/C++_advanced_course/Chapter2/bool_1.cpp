
#include <iostream>

using std::cout;
using std::endl;


void test_1()
{
	bool bvar = false;
	int i = 5, j = 5;
	bvar = i == j;
	cout << bvar << endl;
	// bvar���ᵱ������1���Դ�
	cout << bvar + i << endl;

	// �����ʾ�Ľ�һ�����ͱ�����ֵ�������������������������һ�����棬
	// ����һ��Ҫ���bool������ֵֻ����0��1
	bvar = i;
}


int main()
{
	test_1();

	system("pause");
	return 0;
}