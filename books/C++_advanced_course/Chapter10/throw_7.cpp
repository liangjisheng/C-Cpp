
// throw����׳�һ������ʱ���ṹ��һ���µĶ��������������쳣����
// �ö���������ڴӱ��׳�ʱ��ʼ���㣬һֱ����ĳ��catch��䲶׽���ͻ���
// ��catch����ִ����Ϻ�����
// ĳЩ����£��������е�catch��֧���޷���׽���쳣���⽫���µ�ǰ����
// ִ�еĽ����������ص����������У������������У����������ϵĲ�׽�쳣
// �Ĺ��̣�֪���쳣����׽�����ս����������������

#include <iostream>

using namespace std;

class ExClass
{
	int num;
public:
	ExClass(int i)
	{
		cout << "Constructor exception object with num = " << i << endl;
		num = i;
	}
	ExClass(ExClass &e)
	{
		cout << "After copy constructor num = " << e.num + 1 << endl;
		num = e.num + 1;
	}
	~ExClass() { cout << "Destructing exception object with num = " << num << endl; }

	void show() { cout << "The number is " << num << endl; }
};

void ThrowExFunc()
{
	try{
		// �׳��쳣����������û���ں���ThrowExFunc�б�����������������
		// ThrowExFunc��ִ�н���(��������:After catch statement)
		throw ExClass(199);
	}
	catch(double){
		cout << "Exception catched!" << endl;
	}
	cout << "After catch statement" << endl;
}


int main()
{
	try{
		ThrowExFunc();
	}
	catch(ExClass e){
		e.show();
	}
	catch(...){
		cout << "All will fall in" << endl;
	}
	cout << "Continue to execute";

	system("pause");
	return 0;
}