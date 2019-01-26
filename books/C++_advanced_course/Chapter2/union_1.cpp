
#include <iostream>

using std::cout;
using std::endl;

union testunion
{
	char c;
	int i;
};


void test_1()
{
	cout << sizeof(testunion) << endl;
	testunion *pt = new testunion;
	char *p = reinterpret_cast<char*>(pt);
	for(int i = 0; i < sizeof(*pt); i++)
		cout << (int)p[i] << " ";
	cout << endl;

	cout << pt->i << endl;
	// �޸�һ�����ݳ�Ա��һ����ͬʱ�ı������������ݳ�Ա��ֵ
	pt->c = 'A';
	cout << pt->c << endl;
	for(int i = 0; i < sizeof(*pt); i++)
		cout << (int)p[i] << " ";
	cout << endl;
	cout << pt->i << endl;

	delete pt;
	pt = NULL;
}


int main()
{
	test_1();

	system("pause");
	return 0;
}