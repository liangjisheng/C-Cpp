
// ��catch�Ӿ��н����쳣ƥ��ʱ���Խ�����������ת��:��һ���������������ת��
// һ��������������catch�Ӿ�Ҳ���Դ������������͵��쳣������ת���������ڴ�ֵ��
// �����Լ�ָ����.�ڶ����������һ�����ͻ�ָ��(typed pointer)ת��Ϊ������ָ��
// (untyped pointer),���Դ���const void*ָ���catch�Ӿ��ܲ����κ����͵�ָ���쳣

#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	stuff() { n = c = 0; }
	stuff(stuff&)
	{
		cout << "stuff's copy constructor invoked" << endl;
		cout << this << endl;
	}
};

class SpecialStuff : public stuff
{
	double d;
public:
	SpecialStuff() { d = 0.0; }
	SpecialStuff(SpecialStuff&)
	{
		cout << "SpecialStuff's copy constructor invoked" << endl;
		// cout << this << endl;
		Addr();
	}
	void Addr() { cout << this << endl; }
};

void passAndThrow()
{
	SpecialStuff localStuff;
	localStuff.Addr();
	throw localStuff;
}

void throwPointer()
{
	static int i = 4;
	throw &i;
}


int main()
{
	try{
		passAndThrow();
	}
	catch(stuff &w){
		cout << "catched" << endl;
		cout << &w << endl;
	}

	cout << endl;
	try{
		throwPointer();
	}
	catch(void *p){
		cout << "catched pointer is " << p << endl;
	}

	system("pause");
	return 0;
}