
#include <iostream>

using std::cout;
using std::endl;

void increase(int &r) { r++; }


int main()
{
	int i = 5;
	int *p = &i;
	int &ri = *p;			// 变量ri和变量p具有相同的值
	ri++;
	cout << *p << endl;

	int j = *p;
	increase(j);
	cout << j << endl;
	cout << *p << endl;

	increase(*p);			// 对指针解引用并不会产生一个新的无名对象
	cout << *p << endl;

	system("pause");
	return 0;
}

