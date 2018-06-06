
// dynamic_cast��һ������̬�������������ֻ������ָ������ü��ת��������
// dynamic_cast�������������ָ��(������),ָ����ָ�Ķ���(���������󶨵Ķ���)
// ����ӵ���麯����Ա���������ֱ������
// dynamic_cast���Խ������µ�ת������ָ������ָ��(����)��ָ���������ָ��
// (����)֮�����ת�����ڶ��ؼ̳е�����£���������Ķ������֮�����ת��
// (��Ϊ����ת��:crosscast)
// ĳЩ�������У���Ϊ���������ָ��ת��Ϊָ������ָ�����ǰ�ȫ�ģ���ʱ����
// û�б�Ҫʹ��dynamic_cast���������ˣ���Ҳ����"���湤��",�����������

#include <iostream>

using namespace std;

class A
{
public:
	int i;
	virtual void show() { cout << "class A" << endl; }
	A() { i = 1; }
};

class B : public A
{
public:
	int j;
	// ��B�е�showҲ���麯��������virtualҲ�У�����ü���
	virtual void show() { cout << "class B" << endl; }
	B() { j = 2; }
};

class C : public B
{
public:
	int k;
	virtual void show() { cout << "class C" << endl; }
	C() { k = 3; }
};

void test_1()
{
	A a;
	B *pb = NULL;
	C *pc = NULL;

	// ��̬����ת��������ָ��ת��Ϊ������ָ��,static_cast�����ָ�������ͼ��
	pc = static_cast<C*>(&a);

	// dynamic_cast��Ŀ���Ǽ��ָ����ָ�Ķ����ܷ�ȫ��ת��Ϊclass B����,����
	// ����C++��������Ϊ��������ָ��תΪ����ָ�����ǰ�ȫ�ģ�����ʵ���������
	// dynamic_cast��û�з��Ӷ�̬�������ã����������Ľ��û�����壬����
	// dynamic_cast����������ת��(�ɻ���ָ��ָ��������ָ��)�İ�ȫ�Լ��������Ч
	// �ģ�������ת��(upcast)ʱ�Ƿ���ЧҪ������ı�����ʵ�֣����������ת��ʱ
	// �ɿ��ǲ���������ʽ,����ʹ��dynamic_cast
	pb = dynamic_cast<B*>(pc);
	if(pb)
	{
		pb->show();
		cout << pb->j << endl;
	}
	else
		cout << "Convertion failed" << endl;
}


void test_2()
{
	// dynamic_cast������ת����(downcast)ʱ����������ָ����ָ�Ķ����ʵ��
	// ���ͣ��Ӷ�����ת���Ƿ�ɹ�
	A *pa = NULL;
	B b, *pb;
	C *pc;

	pb = dynamic_cast<B*>(pa);
	if(!pb)
		cout << "Result is NULL" << endl;

	pa = &b;
	pb = dynamic_cast<B*>(pa);
	if(pb)
	{
		pb->show();
		cout << pb->j << endl;
	}
	else
		cout << "Convertion failed" << endl;

	pc = dynamic_cast<C*>(pa);
	if(pc)
	{
		pc->show();
		cout << pc->k << endl;
	}
	else
		cout << "Convertion failed" << endl;
}


class Other
{
	virtual void func(){}
};


void test_3()
{
	// ָ��ת��ʧ��������ɷ���ֵ�Ƿ�ΪNULL�������жϣ���C++�в�����
	// �����ã��������õ�װ��ʧ��Ҫ�����쳣����ʾ
	A a, *pa;
	C c;
	Other o;
	bool bad;

	// try to set reference from Other& to B&
	try{
		bad = false;
		B &rb = dynamic_cast<B&>(o);
	}
	catch(bad_cast e){
		cout << e.what() << endl;
		cout << "Reference failed from Other& to B&" << endl;
		bad = true;
	}
	if(!bad)
	{
		B &rb = dynamic_cast<B&>(o);
		rb.show();
	}

	// try to set reference from A& to B&
	pa = &a;
	try{
		bad = false;
		B &rb = dynamic_cast<B&>(*pa);
	}
	catch(bad_cast e){
		cout << e.what() << endl;
		cout << "Reference failed from A& to B&" << endl;
		bad = true;
	}
	if(!bad)
	{
		B &rb = dynamic_cast<B&>(*pa);
		rb.show();
	}

	// try to set reference from C& to B&
	try{
		bad = false;
		B &rb = dynamic_cast<B&>(c);
	}
	catch(bad_cast e){
		cout << e.what() << endl;
		cout << "Reference failed from C& to B&" << endl;
		bad = true;
	}
	if(!bad)
	{
		B &rb = dynamic_cast<B&>(c);
		rb.show();
	}
}


int main()
{
	// test_1();
	// test_2();
	test_3();

	system("pause");
	return 0;
}