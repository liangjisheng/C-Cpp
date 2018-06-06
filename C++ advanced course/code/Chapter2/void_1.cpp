
// void表示无类型的意思，由于void不是一种数据类型，所以不能用它来定义一个变量
// void a;		// error

// vodi 可用在下面的几个场合
// (1)对函数的返回值的限定，Add(int,int){...},在C编译器中会认为函数Add的返回值
// 是int，而C++的类型检查更为严格，C++不允许这种写法，如果没有返回值，必须用void
// (2)对函数参数的限定，int f(){...}在C中不给出任何参数的说明，那么函数可以接受
// 任意数量的参数，如果要定义一个不接受任何参数的函数必须用void，int f(void){...}
// 但在C++中，这两种声明是一样的，都表示不接受任何参数

// C++中允许定义void*类型的指针，它纯粹代表一个地址，而不对该地址出的内容做
// 任何解释。因此任何类型的指针都可以直接赋值给他，无需进行强制类型转换
// 返过来的话，必须使用强制类型转换
// ANSI标准规定，是不能对void指针进行加减运算，因为他认为进行加减运算的指针
// 必须知道其指向数据类型的大小，实际上，改变void类型的指针的值并不是一件困难
// 的事，只要将他先转换成其他类型的指针，然后在转换回void*类型就可以了


#include <iostream>

using std::cout;
using std::endl;

void test_void()
{
	int i = 9;
	// 指针的强制转换意味着对同一地址处的地址作出不同的解释，因此使用时要小心
	float *p = (float*)&i;
	cout << i <<endl;
	cout << *p << endl;
}


void test_void_1()
{
	char str[] = "abc";
	void *p = str;
	cout << str << endl;
	cout << p << endl;

	// 输出指针变量中存储的地址值，如果确实想查看一个指针所代表的地址值，
	// 应该将其转换成void*后再输出
	p = (void *)((char*)p + 1);
	cout << p << endl;

	p = (void *)((int*)p + 1);
	cout << p << endl;

	p = (void *)((float*)p + 1);
	cout << p << endl;

	p = (void *)((double*)p + 1);
	cout << p << endl;
}


int main()
{
	// test_void();
	test_void_1();

	system("pause");
	return 0;
}