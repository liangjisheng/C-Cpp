
#include <iostream>

using std::cout;
using std::endl;

void increase(int &r) { r++; }


int main()
{
	int i = 5;
	int *p = &i;
	int &ri = *p;			// ����ri�ͱ���p������ͬ��ֵ
	ri++;
	cout << *p << endl;

	int j = *p;
	increase(j);
	cout << j << endl;
	cout << *p << endl;

	increase(*p);			// ��ָ������ò��������һ���µ���������
	cout << *p << endl;

	system("pause");
	return 0;
}

