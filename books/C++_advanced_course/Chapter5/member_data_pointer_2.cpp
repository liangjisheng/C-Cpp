
// 成员数据指针是在底层实现的，存放的是对象的数据成员相对于对象首地址的偏移量
// 从这个意义上来说，成员数据指针并不是一个真正的指针，通过该指针获得数据时，
// 实际上是将该指针表示的偏移量加到对象首地址上

#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
	int age;
	double score;
	Student(int a, double s) { age = a; score = s; }
};

void PrintContent(void *addr, int n)
{
	char *p = (char*)addr;
	for(int i = 0; i < n; i++)
		cout << (int)p[i] << " ";
	cout << endl;
}


int main()
{
	Student me(20, 75.5);
	int Student::* pi;
	double Student::* pd;

	cout << sizeof(pi) << endl;
	cout << sizeof(pd) << endl;
	pi = &Student::age;
	pd = &Student::score;
	PrintContent(&pi, 4);			// 查看成员函数指针的内容
	PrintContent(&pd, 4);

	system("pause");
	return 0;
}