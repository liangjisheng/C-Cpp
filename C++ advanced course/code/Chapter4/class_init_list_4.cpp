
// 在初始化列表中，无法完成为对象的数组成员进行初始化的工作，原因是C++语言没有
// 这样的机制，所以只能在构造函数体内分别为成员数组的每个元素分别赋初值，如果
// 数组元素本身也是对象，那么这种复制操作会造成较大的运行时开销。
// 无法在类中定义一个常量数组，因为无法为对象的常量数组成员初始化，实际中通常
// 定义静态的常量数组，如果确实想在类中定义一个常量数组，一个变通的做法是定义
// 一个指向常量的指针常量，然后在初始化列表中为他初始化

#include <iostream>

using std::cout;
using std::endl;


int* CreateArr(int n)
{
	int *p = NULL;
	p = new int[n];
	for(int i = 0; i < n; i++)
		p[i] = i + 1;
	return p;
}


class A
{
	int arrsize;
	const int *const arr;
public:
	A() : arr(CreateArr(0)) 
	{
		arrsize = 0; 
		cout << "default constructor" << endl;
	}
	A(int n) : arr(CreateArr(n)) { arrsize = n; }
	void show()
	{
		for(int i = 0; i < arrsize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	~A() { delete[] arr; }
};


int main()
{
	A a(3);
	a.show();

	// 并没有调用A的构造函数
	A *ptr = NULL;

	system("pause");
	return 0;
}