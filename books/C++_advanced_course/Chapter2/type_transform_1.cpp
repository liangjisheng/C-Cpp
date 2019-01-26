
// static_cast相当于传统C语言中的哪些"较为合理"的强制类型转换，比较多的使用与
// 与基本数据类型之间的转换、基类对象指针(引用)和派生类对象指针(引用)之间的转
// 换、一般的指针和void*类型的指针之间的转换等
// 两个互不相关的类不允许通过static_cast进行转换，static_cast进行的转换是一种
// 静态转换，是在编译是决定的，编译后，空间和实际效率实际上等价于C方式强制转换


#include <iostream>

using std::cout;
using std::endl;

class A
{
	char ch;
	int n;
public:
	A(char c, int i) : ch(c), n(i) {}
};


void test_1()
{
	A a('s', 2);
	// char *p = static_cast<char*>(&a);			// invalid type conversion
	// 可以通过void*为中介实现转换
	void *q = &a;
	char *p = static_cast<char*>(q);
	cout << *p << endl;

	for(int i = 0; i < sizeof(A); i++)
		cout << (int)p[i] << " ";
	cout << endl;
}


int main()
{
	test_1();

	system("pause");
	return 0;
}