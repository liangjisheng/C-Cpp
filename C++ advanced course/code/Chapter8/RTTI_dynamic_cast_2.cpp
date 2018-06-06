
// ����ת��(crosscast)��������ƽ�е������֮����У���������ûʲô��ϵ��������
// ��һ��ת��Ϊ��һ���ǲ����еģ����ǣ������A����B����ĳ��������C�Ļ��࣬��ָ��
// ��ָ�Ķ��������һ����C�Ķ�����ô�ö���ȿ��Ա���Ϊ��A�Ķ���Ҳ���Ա���Ϊ
// ��B�Ķ�������A*(A&)��B*(B&)֮���ת���ͳ�Ϊ����

#include <iostream>

using namespace std;

class A
{
public:
	int num;
	A() { num = 4; }
	virtual void funcA() {}
};

class B
{
public:
	int num;
	B() { num = 5; }
	virtual void funcB() {}
};

class C : public A, public B{};


int main()
{
	C c;
	A *pa;
	B *pb;
	
	pa = &c;
	cout << pa->num << endl;
	pb = dynamic_cast<B*>(pa);
	// �����dynamic_cast�滻��static_cast�������޷����룬���Ǳ�������
	// ��Ϊ��A����B�������޹ص���
	// pb = static_cast<B*>(pa);
	// pa��pb���8���ֽڣ�������class A�Ĵ�С��
	cout << "pa = " << pa << endl;
	if(pb)
	{
		cout << "pb = " << pb  << endl;
		cout << "Convertion succeed" << endl;
		cout << pb->num << endl;
	}
	else
		cout << "Convertion failed" << endl;

	system("pause");
	return 0;
}

