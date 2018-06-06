
// 如果定义一个变量的语句是合法的，那么在这条语句之前加上typedef就一定是
// 合法的，并且原来的变量名就成为类型的新名。
// 使用typedef的关键，是能够正确理解C++中复杂类型的声明

#include <iostream>

using namespace std;

int Add(int, int);
int Sub(int, int);
int Mul(int, int);
int Div(int, int);

// 定义指向这类函数的指针类型
typedef int(*FP_CALC)(int, int);

// 声明一个函数s_calc_func，它根据操作字符op,返回指向相应的计算函数的指针
int (*s_calc_func(char op))(int, int);

// 声明一个函数calc_func,它的作用与s_calc_func相同，但声明语句要简单的多
FP_CALC calc_func(char op);

// 根据op，返回相应的计算结果
int calc(int a, int b, char op);

int Add(int a, int b)
{
	return  a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return b ? a / b : -1;
}


int(*s_calc_func(char op))(int, int)
{
	return calc_func(op);
}

FP_CALC calc_func(char op)
{
	switch(op)
	{
	case '+': 
		return Add;
		break;
	case '-': 
		return Sub;
		break;
	case '*':
		return Mul;
		break;
	case '/':
		return Div;
		break;
	default:
		return NULL;
		break;
	}
}

int calc(int a, int b, char op)
{
	FP_CALC fp = calc_func(op);
	// 下面这行是不用typedef,而直接实现指向函数的指针的例子，可读性较差
	// ASSERT(fp == s_fp),可以断言他们是相等的
	int (*s_fp)(int, int) = s_calc_func(op);

	if(fp)
		return fp(a, b);
	else
		return -1;
}


int main()
{
	int a = 100, b = 20;
	cout << "calc(" << a << ", " << b << ", +) = " << calc(a, b, '+') << endl;
	cout << "calc(" << a << ", " << b << ", -) = " << calc(a, b, '-') << endl;
	cout << "calc(" << a << ", " << b << ", *) = " << calc(a, b, '*') << endl;
	cout << "calc(" << a << ", " << b << ", /) = " << calc(a, b, '/') << endl;

	system("pause");
	return 0;
}


// int (*Register(int(*pf)(const char*, const char*)))(const char*, const char*);


