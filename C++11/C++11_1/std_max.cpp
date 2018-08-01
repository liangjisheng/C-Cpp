
// 接受比较规则的max
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;

// function that compares two pointers by comparing the values to which they point
// 在某个指定规则下，判断第一个参数是否小于第二个参数
// 如果指定的规则是判断第一个参数是否大于第二个参数，则得到的结果正好相反
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
