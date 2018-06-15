
#include <iostream>

using std::cout;
using std::endl;

// ģ��Ԫ��̵�Ŀ�����ڱ�����ִ��һЩ���㣬��������������ִ�С�
// Ԫ��̻�������C++֮�ϵ�һ��С�ͱ�����ԡ�

// ������ʾ���ڱ����Ǽ���һ�����Ľ׳ˣ�ʹ�õ�ģ��ݹ飬
// ��Ҫһ���ݹ�ģ�������ֹͣ�ݹ�Ļ���ģ�壬0�Ľ׳�Ϊ1����������ģ��

template<unsigned char f>
class Factorial
{
public:
	static const unsigned long long val = (f * Factorial<f - 1>::val);
};


// ����ģ����ػ�
template<>
class Factorial<0>
{
public:
	static const unsigned long long val = 1;
};


// test
int main()
{
	cout << Factorial<6>::val << endl;

	system("pause");
	return 0;
}