
// C++֧�����أ���C��֧�����أ��������ԭ��ȫ�ֱ���������C++�������
// ���ſ��е�������C���Բ�ͬ

#include <iostream>

using std::cout;
using std::endl;

int gvar = 5;

void testfunc() { gvar++; }

int testfunc(int para) { return para + 1; }


int main()
{
	cout << gvar << endl;
	testfunc();
	cout << gvar << endl;
	cout << testfunc(gvar) << endl;

	system("pause");
	return 0;
}