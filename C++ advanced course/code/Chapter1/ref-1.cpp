
#include <iostream>

using std::cout;
using std::endl;

// 引用确实是一个变量，它存放的是被引用对象的地址，引用变量在功能上相当于一个
// 指针常量，即一旦指向某个单元就不能在指向别处。在底层，引用变量也是按指针常量
// 的方式来实现的

// int i = 5;
// int &ri = i;
// ri = 8

// int i = 5;
// int * const pi = &i;
// *pi = 8;

// 指针常量与引用变量的关系
// 1.在内存中占4字节空间，存放的都是被引用对象的地址，都必须在定义的同时初始化
// 2.指针常量(pi为例)允许寻址，即&pi返回指针变量(常变量)本身的地址，被引用对象
// 用*pi表示;引用变量(ri为例)不允许寻址，&ri返回的是被引用对象的地址(就是变量ri自身的值)
// 而不是变量ri的地址(ri的地址由编译器掌握，程序员无法直接对它进行存取)
// 被引用对象直接用r表示
// 3.凡是使用引用变量的代码，都可以转换成使用指针常量的对应形式的代码，只不过书写
// 上要繁琐一些。引用变量书写上方便，但指针常量能实现的功能，引用变量不一定能实现
// int i = 5, j = 6;
// int* const array[] = {&i, &j};			// ok
// int& array_rer[] = {i, j};				// error

int main()
{
	// 在特定的环境下，利用特殊的手段，可以在运行时动态的改变一个引用变量与被引用
	// 对象的对应关系，使引用变量指向一个别的对象
	// 下面的代码仅限在32位，如果在64位上从指针转换为int可能会发生截断从而丢失数据
	// 如果引用的不是int型，考虑到对齐等因素，要准确计算引用变量在内存中的地址也不是
	// 一件容易的事，可能跟具体的编译器和环境有关。

	int i = 5;
	int j = 6;
	int &ri = i;
	void *pi, *pj;
	int *addr;
	int dis;
	pi = &i;
	cout << pi << endl;
	pj = &j;
	cout << pj << endl;

	dis = (int)pj - (int)pi;
	int dis1 = (int)pi - (int)pj;
	// 变量i与变量j的地址相差12个字节
	cout << "(int)pi - (int)pj = " << dis1 << endl;
	cout << "(int)pj - (int)pi = " << dis << endl;
	addr = (int*)((int)pj + dis);		// 计算引用变量ri在内存中的地址
	cout << "引用变量ri在内存中的地址 = " << addr << endl;
	(*addr) += dis;						// 将引用ri所指向的对象由变量i转变成变量j
	ri = 10;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;

	system("pause");
	return 0;
}