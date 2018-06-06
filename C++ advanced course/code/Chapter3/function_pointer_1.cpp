
// C++��Ա����ָ���ʹ��

#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	int RetInt() { return 100; }
};

class B
{
public:
	int (A::*pFun)(void);			// ������һ��ָ����A�еĳ�Ա����ָ��
	void Print(A &obj)
	{
		int val = (obj.*pFun)();
		cout << "Val = " << val << endl;
	}
};


int main()
{
	A a;
	B b;
	// Ϊ��Ա����ָ�븳ֵ��ʱ�򣬲�����Ҫ�ƶ������������Ķ���
	// ȡĳ����ĳ�Ա�����ĵ�ַ��������ʾʹ��ȡ��ַ�����&,�����ⲿ����ȡ
	// ��ڵ�ַ��Ҫ��ͬ��ԭ���Ǳ����������ͨ��̬��Ա�����
	b.pFun = &A::RetInt;
	// ���õ�ʱ��ָ����������������Ķ���
	b.Print(a);

	system("pause");
	return 0;
}