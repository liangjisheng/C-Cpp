
// ���ô����õķ�ʽ��׽�쳣ʱ�����п��ܷ����麯������

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void what() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
	virtual void what() { cout << "Derived" << endl; }
};

void f() { throw Derived(); }


int main()
{
	try{
		f();
	}
	catch(Base b){
		b.what();
	}

	try{
		f();
	}
	catch(Base &b){
		b.what();
	}

	system("pause");
	return 0;
}