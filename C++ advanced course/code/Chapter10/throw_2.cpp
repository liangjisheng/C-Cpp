
// ���쳣���󱻿���ʱ�������������ɶ���Ŀ������캯����ɵģ��ÿ������캯����
// ����ľ�̬����(static type)����Ӧ��Ŀ������캯���������Ƕ���Ķ�̬����
// (dynamic type)��Ӧ����Ŀ������캯��

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
	SpecialStuff() { d = 0; }
	SpecialStuff(SpecialStuff&)
	{
		cout << "SpecialStuff's copy constructor invoked" << endl;
		Addr();
	}
	void Addr() { cout << this << endl; }
};

void passAndThrow()
{
	SpecialStuff localStuff;
	localStuff.Addr();
	stuff &sf = localStuff;
	cout << &sf << endl;
	// �׳�stuff���͵��쳣,����stuff��Ŀ������캯������ʹsf���õ���
	// һ��SpecialStuff���͵Ķ��󣬱���������ݱ��׳�����(������sf)��
	// ��̬����(static type)stuff��������SpecialStuff��������Ӧ���쳣����
	throw sf;
}


int main()
{
	try{
		passAndThrow();
	}
	catch(stuff &w){
		cout << "catched" << endl;
		// w���õľ����쳣����,�������ĵ�ַ���쳣����ĵ�ַ��һ����
		cout << &w << endl;
	}

	cout << endl;
	try{
		passAndThrow();
	}
	// stuff�Ŀ������캯��������������,������ΪlocalStuffͨ���������캯��
	// ���ݸ��쳣���󣬶��쳣������ͨ���������캯�����ݸ�catch�Ӿ��еĶ���w
	// ʵ���ϣ��׳��쳣�����ɵ��쳣������һ����ʱ��������һ�ֳ���Ա���ɼ�
	// �ķ�ʽ�ڷ�������
	catch(stuff w){
		cout << "catched" << endl;
		cout << &w << endl;
	}

	system("pause");
	return 0;
}

