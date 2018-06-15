
#include<iostream>
#include<typeinfo.h>

using std::cout;
using std::endl;

// auto������C++14�п�����Ϊ�����ķ���ֵ
auto AddTest(int a, int b) { return a + b; }

int main()
{
	// ���������������ģ�ȷ��auto��������������
	auto index = 10;
	auto str = "abc";
	auto ret = AddTest(1, 2);
	std::cout << "index:" << index << std::endl;
	std::cout << "str:" << str << std::endl;
	std::cout << "res:" << ret << std::endl;

	cout << "typeid(index) = " << typeid(index).name() << endl;
	cout << "typeid(str) = " << typeid(str).name() << endl;
	cout << "typeid(ret) = " << typeid(ret).name() << endl;

	system("pause");
	return 0;
}