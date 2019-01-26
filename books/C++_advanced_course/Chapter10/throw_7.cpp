
// throw语句抛出一个对象时，会构造一个新的对象，这个对象就是异常对象
// 该对象的生命期从被抛出时开始计算，一直到被某个catch语句捕捉，就会在
// 该catch语句块执行完毕后被销毁
// 某些情况下，可能所有的catch分支都无法捕捉到异常，这将导致当前函数
// 执行的结束，并返回到主调函数中，在主调函数中，将继续以上的捕捉异常
// 的过程，知道异常被捕捉或最终结束整个程序的运行

#include <iostream>

using namespace std;

class ExClass
{
	int num;
public:
	ExClass(int i)
	{
		cout << "Constructor exception object with num = " << i << endl;
		num = i;
	}
	ExClass(ExClass &e)
	{
		cout << "After copy constructor num = " << e.num + 1 << endl;
		num = e.num + 1;
	}
	~ExClass() { cout << "Destructing exception object with num = " << num << endl; }

	void show() { cout << "The number is " << num << endl; }
};

void ThrowExFunc()
{
	try{
		// 抛出异常对象，由于它没有在函数ThrowExFunc中被捕获，所以它导致了
		// ThrowExFunc的执行结束(否则会输出:After catch statement)
		throw ExClass(199);
	}
	catch(double){
		cout << "Exception catched!" << endl;
	}
	cout << "After catch statement" << endl;
}


int main()
{
	try{
		ThrowExFunc();
	}
	catch(ExClass e){
		e.show();
	}
	catch(...){
		cout << "All will fall in" << endl;
	}
	cout << "Continue to execute";

	system("pause");
	return 0;
}