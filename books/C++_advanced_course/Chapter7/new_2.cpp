
#include <iostream>
using namespace std;

// 使用new和new[]申请空间时，系统会在要求申请的空间大小之外额外申请一块空间
// 放在返回给用户的空间的前面，存放诸如给用户申请空间的字节数、申请对象的个数
// 等信息，PrintContent()用来在给定地址空间处，倒退若干个整数(int)变量的空间
// 然后将这几个值输出

// 当用new申请空间时，由于只需要用delete释放空间就行了，并不涉及多次调用被释放
// 的对象的析构函数的问题，所以不用存放申请元素的个数，观察输出，在返回地址处
// 倒退第4整数处存放的用户申请的空间的字节数
// 当用new[]申请空间时，根据被申请对象的数据类型的具体情况，有两种安排，
// 如果申请的是基本数据类型的数据，或者虽然申请的是类类型的数据，但在释放的时候
// 并不需要调用析构函数(如class A)那么额外的信息排列顺序与用new操作申请时相同
// 如果申请的是类类型数据，并且在释放的时候需要调用析构函数(如class B)，那么在
// 返回地址处倒退第5整数处存放的用户申请空间的字节数(在加4，这4个字节是在申请
// 数据的最后作为分割符的)，在倒退第1整数处存放动态数组元素的个数

void PrintContent(void *addr, int offset)
{
	char *s = (char*)addr;
	int *p = (int*)(s - offset * 4);
	for(int i = 0; i < offset; i++)
		cout << p[i] << " ";
	cout << endl;
}

class A
{
	char c[10];
};

class B
{
	char c[10];
public:
	~B() {}
};


int main()
{
	int *p = new int[5];
	PrintContent(p, 5);
	delete []p;

	char *s = new char[100];
	PrintContent(s, 5);
	delete []s;

	double *q = new double;
	PrintContent(q, 5);
	delete q;

	A *a1 = new A;
	PrintContent(a1, 5);
	delete a1;

	A *a2 = new A;
	PrintContent(a2, 5);
	delete a2;

	B *b1 = new B;
	PrintContent(b1, 5);
	delete b1;

	B *b2 = new B[5];
	PrintContent(b2, 5);
	delete []b2;

	system("pause");
	return 0;
}