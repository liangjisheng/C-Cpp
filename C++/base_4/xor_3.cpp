
// 异或运算,二进制位相同为0,相异为1
// 0^0 = 0
// 0^1 = 1
// 1^0 = 1
// 1^1 = 0
// 0与任何数异或等于任何数
// 1异或任何数等于任何数取反
// 任何数异或自己等于把自己置0

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;


// 使用异或交换两个数
template<class T>
void swap_XOR(T* t1, T* t2);

// 右移运算，右移n位的时候，最右边的n位将被丢弃
// 如果数字是一个无符号数值，则用0填补最左边的n位
// 如果数字是一个有符号数值，则用数字的符号位填补最左边的n位
// 也就是说如果数字原先是一个正数，则右移之后再最左边补n个0
// 如果数字原先是负数，则右移之后在最左边补n个1


int main()
{
	int a = 0xa1;
	int b = 0x05;
	cout << "Before swap:" << endl;
	cout << hex << a << endl;
	cout << hex << b << endl;
	swap_XOR(&a, &b);
	cout << "After swap:" << endl;
	cout << hex << a << endl;
	cout << hex << b << endl;

	system("pause");
	return 0;
}

template<class T>
void swap_XOR(T* t1, T* t2)
{
	*t1 = *t1^*t2;
	*t2 = *t2^*t1;
	*t1 = *t1^*t2;
}