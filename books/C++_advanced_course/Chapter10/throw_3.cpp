
// �쳣�����ڱ������׳�ʱ�������ֲ�ͬ��ѡ��

#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	stuff() { n = c = 0; }
	stuff(stuff &) { cout << "stuff's copy constructor invoked" << endl; }
};

void passAndThrow()
{
	stuff localStuff;
	throw localStuff;
}

void rethrow1()
{
	try{
		passAndThrow();
	}
	catch(stuff &w)
	{
		cout << &w << endl;
		// �����׳����ǵ�ǰ������쳣������Ϊû�з����������캯���ĵ���
		throw;
	}
}

void rethrow2()
{
	try{
		passAndThrow();
	}
	catch(stuff &w)
	{
		cout << &w << endl;
		// �����׳����ǵ�ǰ�����쳣��һ���µĿ���
		// һ����˵��Ӧ����throw�������׳���ǰ���쳣����Ϊ��������ı䱻����
		// ��ȥ���쳣���ͣ����Ҹ���Ч�ʣ���Ϊ��������һ���¿���
		throw w;
	}
}


int main()
{
	try{
		rethrow1();
	}
	catch(stuff &w)
	{
		cout << "catched rethrow1" << endl;
		cout << &w << endl;
	}

	cout << endl;
	try{
		rethrow2();
	}
	catch(stuff &w)
	{
		cout << "catched rethrow2" << endl;
		cout << &w << endl;
	}

	system("pause");
	return 0;
}