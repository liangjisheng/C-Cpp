
#include <iostream>

using std::cout;
using std::endl;


void test()
{
	int i = 10;
	int a = i;

	cout << a << endl;
	_asm{
		mov dword ptr[ebp - 4], 80
	}
	// 编译器默认把i的值放入寄存器中，每次访问i只需从寄存器中获得即可
	// 上面的汇编代码已经修改了i的值，但只是修改了寄存器中的值
	// 并没有修改主存中的值，所以反映不到b上，b仍为10
	// 如果i是一个被多个任务共享的变量，这种优化带来的错误可能是致命的
	int b = i;
	cout << b << endl;
}


void test_1()
{
	// 使用volatile来抑制编译器的优化
	volatile int i = 10;
	int a = i;

	cout << a << endl;
	_asm{
		mov dword ptr[ebp - 4], 80
	}

	// Debug模式下b为10，Release模式下b为80，要注意区分
	// 这次访问i的时候，是直接从主存中访问的，而不是从寄存器中访问的
	int b = i;
	cout << b << endl;
}


void test_2()
{
	// 代码优化可能会将一些"无用"的代码彻底去除，如果确实想在执行文件中保留这部分
	// 代码的话，也可以将其中的变量声明为volatile
	int i, j, k;
	int s;
	// 编Release的时候，下面的三重循环会直接优化为一条赋值语句s = 5;
	// 如果不想优化，可以将s声明为volatile
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			for(k = 0; k < 5; k++)
				s = 5;
	cout << s << endl;
}


int main()
{
	test();
	test_1();
	test_2();

	system("pause");
	return 0;
}