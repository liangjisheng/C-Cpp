
// ��ʱ����һ���������������������ܺ����ķ���ֵ������ʵ����ʽ������ת��
// const A &ra = 5; ����5��һ�����ֳ������޷�Ѱַ�����Ա�������5ת����һ��
// A�����ʱ����������ʱ�����ʼ������ra

#include <iostream>

using std::cout;
using std::endl;

class X
{
	static  int order;
	char ch;
	int n;
public:
	X(char c)
	{
		order++;
		n = order;
		ch = c;
		cout << "Constructing object" << n << endl;
	}
	~X() { cout << "Destructing object" << n << endl; }
	X(X& x)
	{
		order++;
		n = order;
		ch = x.ch;
		cout << "Constructing object " << n << " by copying" << endl;
	}
	X& operator=(const X& x)
	{
		cout << "operator=" << n << endl;
		ch = x.ch; 
		return *this; 
	}
};


int X::order;

X makewho()
{
	X B('B');
	return B;
}

// ���ĳ������������һ�����������return�����ֱ�ӵ�����Ĺ��캯������
// ����ù��캯����thisָ��һ����������������������������Ԥ�����ܷ���ֵ��
// ��Ƭ�ռ���׵�ַ
X makewho_1() {	return X('B'); }


int main()
{
	X A('A');
	// ������������������һ����ʱ������ʱ����Ŀռ�����������(main)�ڵ���
	// makewho()֮ǰ�ͷ�����
	A = makewho();

	cout << endl;
	X A1 = makewho_1();

	system("pause");
	return 0;
}