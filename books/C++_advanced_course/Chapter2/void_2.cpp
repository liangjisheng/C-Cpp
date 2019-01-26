
// void* memcpy(void *dest, void *src, size_t len);
// void* memset(void *buffer, int c, size_t num);
// 任何类型的指针都可以传入memcpy和memset中，这也真实体现了内存操作函数的意义
// 因为它的操作对象仅仅是一片内存，而不论这片内存时什么类型

#include <iostream>

using std::cout;
using std::endl;

class A
{
	int arr[2];
	int i;
	double d;
public:
	A(){ memset(this, 0, sizeof(A)); }
	// 可以认为使用memcpy是实现类的默认拷贝构造函数的一种可行方案，同时可以
	// 看出，如果类A中存在只读成员变量，函数memset()和memcpy()的执行会改变
	// 只读成员变量的值
	A(const A& a) { memcpy(this, &a, sizeof(A)); }
	void set(int, int, int, double);
	void show();
};

void A::set(int a0, int a1, int iv, double dv)
{
	arr[0] = a0;
	arr[1] = a1;
	i = iv;
	d = dv;
}

void A::show()
{
	cout << arr[0] << " " << arr[1] << " " << i << " " << d << endl;
}


int main()
{
	A obj;
	obj.show();
	obj.set(1, 2, 3, 4.8);
	A another = obj;
	another.show();

	system("pause");
	return 0;
}