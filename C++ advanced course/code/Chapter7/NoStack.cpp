
// 如果想禁止在栈上创建对象，可以将构造函数变成私有的，但这也会影响new操作,
// 所有可以将类的析构函数设为私有的

#include <iostream>

using namespace std;

class NonStack
{
private:
	int num;
	~NonStack();
public:
	NonStack() { num = 1; }
	void show() { cout << num << endl; }
	void Delete() { delete this; }
};

int main()
{
	// 析构函数是私有的，禁止在栈上创建对象
	// NonStack obj;		// error

	NonStack *p = new NonStack;
	p->show();
	p->Delete();		// 销毁时，必须调用Delete函数

	system("pause");
	return 0;
}