
#include <iostream>
using namespace std;

// 如果用new申请的空间用delete[]来释放，那么程序就会在给定的地址的前面寻找数据
// 元素个数(得到的是一个很大的无符号整数)，运行结果是无法预料的；而用new[]申请
// 的空间用delete来释放，则delete操作需要知道的内存块的大小信息无法正确获取(位置不对)
// 也不会多次调用对象的析构函数，这样运行的结果同意是无法预料的

class A
{
	int i;
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};

int main()
{
	A *pA = new A[3];
	int *p = (int*)pA;
	// 申请空间的首地址之前存放申请对象的个数,但只申请一个的话，就不会存放
	cout << *(p -1) << endl;
	delete []pA;

	pA = new A;
	p = (int*)pA;
	cout << *(p - 1) << endl;
	delete pA;
	cout << endl;

	A *pA1 = new A[3];
	int *p1 = (int*)pA1;
	// 设置为1只会调一个对象的析构函数
	*(p1 - 1) = 1;
	delete []pA1;

	system("pause");
	return 0;
}