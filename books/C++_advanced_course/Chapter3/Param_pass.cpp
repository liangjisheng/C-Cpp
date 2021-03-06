
// 要实现函数调用，除了知道函数的入口地址，如果被调函数有参数的话，还要知道
// 如何向被调函数传递参数，_cdecl是C和C++程序默认的函数调用约定，参数按从右
// 到左的顺序压入堆栈，有主调函数(caller)负责维护堆栈(在调用之前将参数压入
// 堆栈，调用完之后将参数弹出栈)。也正是因为用来传送参数的堆栈是由主调函数
// 维护的，所以实现可变参数的函数只能使用这种函数调用约定。因为每一个主调函数
// 都要包含清理堆栈的代码，所以编译后的可执行文件的大小要比使用其他调用约定
// (如_stdcall(WINAPI))的程序大。

// ebp被称为帧指针，每一个函数都有属于函数自身的局部的数据，这些数据被称为
// 该函数的帧。一帧数据的起始位置由帧指针ebp指明，而帧的另一端由栈指针esp
// 动态维护。在函数运行期间，帧指针ebp的值保持不变。push ebp就是保留主调
// 函数的帧指针，mov ebp,esp 是建立本函数的帧指针，sub esp,xxx(xxx代表
// 某个正整数)则是为函数的局部变量分配空间。在调试版本下，一个C/C++函数
// 即使没有定义一个局部变量，任然会分配192个字节(16进制数为0C0H)的空间
// 这一部分可以给临时变量使用。如果在函数中定义了局部变量，则会为每个局部
// 变量分配12字节的空间(大于任何基本数据类型变量的需要)

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int i = 10;
	cout << ++i << " " <<  --i << " " << i++ << endl;

	system("pause");
	return 0;
}