
// �ڹ��캯�����׳��쳣���ڸ����Ͻ�����Ϊ�ö���û�б�������ɣ���˵�ǰ�����
// �����������ᱻ���ã�ͬʱ���ڹ��캯������Ҳ��һ���������ں��������׳��쳣��
// ���µ�ǰ�������еĽ��������ͷ��Ѿ�����ľֲ�����.�������ʱ��Ҫִ����ֱ��
// ����Ĺ��캯�������ĳ�Ա����Ĺ��캯�������캯�����׳��쳣���������ٵ�ǰ��
// ��Ķ�����Ҳ����˵��Ҫִ�������ͳ�Ա�������������

#include <iostream>

using namespace std;

class C
{
	int m;
public:
	C() { cout << "in C constructor" << endl; }
	~C() { cout << "in C destructor" << endl; }
};

class A
{
public:
	A() { cout << "in A constructor" << endl; }
	~A() { cout << "in A destructor" << endl; }
};

class B : public A
{
public:
	C c;
	B() { cout << "in B constructor" << endl; throw -1; } 
	~B() { cout << "in B destructor" << endl; }
};


int main()
{
	try{
		B b;
	}
	catch(int){
		cout << "catched" << endl;
	}

	system("pause");
	return 0;
}