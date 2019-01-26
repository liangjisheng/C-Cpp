
// ���ܱȽϹ����max
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;

// function that compares two pointers by comparing the values to which they point
// ��ĳ��ָ�������£��жϵ�һ�������Ƿ�С�ڵڶ�������
// ���ָ���Ĺ������жϵ�һ�������Ƿ���ڵڶ�����������õ��Ľ�������෴
bool int_ptr_less(int *a, int *b) { return *a < *b; }
bool int_ptr_greater(int *a, int *b) { return *a > *b; }

int main()
{
	int x = 17;
	int y = 42;
	int *px = &x;
	int *py = &y;
	int *pmax = NULL;

	// call max() with special comparison function
	pmax = max(px, py, int_ptr_less);
	cout << *pmax << endl;
	pmax = NULL;
	pmax = max(px, py, int_ptr_greater);
	cout << *pmax << endl;
	cout << endl;

	int *pmin = NULL;
	pmin = min(px, py, int_ptr_less);
	cout << *pmin << endl;
	pmin = min(px, py, int_ptr_greater);
	cout << *pmin << endl;

	system("pause");
	return 0;
}
