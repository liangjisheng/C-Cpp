
// �������һ������������ǺϷ��ģ���ô���������֮ǰ����typedef��һ����
// �Ϸ��ģ�����ԭ���ı������ͳ�Ϊ���͵�������
// ʹ��typedef�Ĺؼ������ܹ���ȷ���C++�и������͵�����

#include <iostream>

using namespace std;

int Add(int, int);
int Sub(int, int);
int Mul(int, int);
int Div(int, int);

// ����ָ�����ຯ����ָ������
typedef int(*FP_CALC)(int, int);

// ����һ������s_calc_func�������ݲ����ַ�op,����ָ����Ӧ�ļ��㺯����ָ��
int (*s_calc_func(char op))(int, int);

// ����һ������calc_func,����������s_calc_func��ͬ�����������Ҫ�򵥵Ķ�
FP_CALC calc_func(char op);

// ����op��������Ӧ�ļ�����
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
	// ���������ǲ���typedef,��ֱ��ʵ��ָ������ָ������ӣ��ɶ��Խϲ�
	// ASSERT(fp == s_fp),���Զ�����������ȵ�
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


