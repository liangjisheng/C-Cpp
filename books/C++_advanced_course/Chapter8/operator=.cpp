
// ��������£���Ҫ�Ը�ֵ�������������أ�һ�Ǹ�ֵ�����ߵı��ʽ���Ͳ�һ��
// (���޷�����ת��),һ����Ҫ�����������ֵ������ֻ��ͨ����ĳ�Ա��������
// ʽ�������أ����˵���ˣ����Ҫ���û��Զ������͵�ֵ���ݸ������������ͱ���
// ֻ��ʹ������ת�����ƣ���������������

#include <iostream>

using namespace std;

class A
{
	int num;
public:
	A() 
	{
		cout << "default ctor" << endl;
		num = 0; 
	}
	A(int i) 
	{
		cout << "single int param ctor" << endl;
		num = i; 
	}
	A(const A& src) 
	{
		cout << "copy ctor" << endl;
		num = src.num;
	}
	A& operator=(const A& src)
	{
		cout << "operato= obj param" << endl;
		num = src.num;
		return *this;
	}
	A& operator=(int i)
	{
		cout << "operato= int param" << endl;
		num = i;
		return *this;
	}

	void show() { cout << num << endl; }
};


int main()
{
	// A a = 5;��a1 = 1��������������ȫ��ͬ�ĺ���
	A a = 5;
	a.show();
	A a1;
	a1 = 1;
	a1.show();

	system("pause");
	return 0;
}