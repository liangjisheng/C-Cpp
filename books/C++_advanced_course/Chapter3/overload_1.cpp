
// ��ͬ�������ж���ĺ��������γ����أ��������γ����أ�C++���ϸ�涨ֻ����
// ͬһ�������ж���ĺ��������γ�����

#include <iostream>

using std::cout;
using std::endl;

void func(char *s) 
{ cout << "This is a global function with name" << s << endl; }

class A
{
	void func() { cout << "This is a member function of A" << endl; }
public:
	void useFunc()
	{
		// func("test");			// A::func()�������ⲿ����func(char*)
		func();
		::func("test");
	}

	// ��ľ�̬��Ա������ʵ����Ա���������γ�����
	static void func(int i) 
	{ cout << "A::func() parameter is " << i << endl; }
};


class B : public A
{
public:
	void useFunc(int i) { cout << "In B's useFunc(), i = " << i << endl; }
};


int main()
{
	A::func(4);
	A a;
	a.useFunc();
	B b;
	// b.useFunc();					// A::useFunc()��B::useFunc()����
	b.useFunc(6);

	system("pause");
	return 0;
}