
// 在程序中多次释放同一块内存，并不一定立即引起程序运行错误，也不一定会
// 导致程序运行是崩溃，这跟具体的编译器实现有关，但是多次释放同一块内存
// 空间绝对是一个编程错误，这个错误可能会再其后的某个时刻导致其他逻辑错误
// 的发送，从而给程序的调试和纠错代理困难

#include <iostream>

using namespace std;

int main()
{
	int *p, *q, *one;

	one = new int;
	if(one)
		cout << one << endl;
	delete one;

	// 将指针one所指向的空间释放之后，p申请的空间就是原来one所指向的单元
	p = new int(3);
	if(p)
		cout << p  << endl;
	delete one;		// 相当于delete p

	// delete one之后，p申请的空间就是原来one所指向的单元，也是p所指向的单元
	q = new int(5);
	if(q)
		cout << q << endl;
	cout << (*p) + (*q) << endl;		// 10
	delete p;
	// delete q;		// 此时p和q是指向相同的地址,两次delete出错

	system("pasue");
	return 0;
}

