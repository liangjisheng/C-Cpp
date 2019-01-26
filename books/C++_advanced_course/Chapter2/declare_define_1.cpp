
// 一般情况下，可以通过改变类定义的位置，可以避免提前声明该类，
// 但这并不是任何时候都行的通的

#include <iostream>

using std::cout;
using std::endl;


class A;

class B
{
public:
	void show(const A& src);
};

class A
{
private:
	int i;
public:
	A(int in) { i = in; }
	friend void B::show(const A& src);
};

void B::show(const A& src) { cout << src.i << endl; }


void test()
{
	int i = 5;
	double d = 6.6;
	typedef int* ptr;
	ptr p1 = &i;
	cout << *p1 << endl;

	// typedef在C++中被当做声明语句，原因是它并不产生新的数据类型
	// 使用typedef时要防止对同一个表示数据类型的标识符作出不同的解释
	// typedef double* ptr;
	// ptr p2 = &d;
	// cout << *p2 << endl;
}


int main()
{
	A a(5);
	B b;
	b.show(a);

	test();

	system("pause");
	return 0;
}

