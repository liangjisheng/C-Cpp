
// union���Զ��幹�캯������Ա������������������������Ϊ����ʹ�ã�
// �������麯���������о�̬���ݳ�Ա�����ó�Ա

#include <iostream>

using std::cout;
using std::endl;


class someClass
{
	int num;
public:
	void show() { cout << num << endl; }
};

// union��Ա��Ĭ�Ϸ���Ȩ����public�ģ�����������Ķ����Ϊ�������ݳ�Ա
// ��Ҫ��ö���������಻�ܶ��幹�캯���������������߸�ֵ������������
union A
{
	char c;
	int i;
	double d;
	someClass s;
};


union B
{
	char c;
	int i;
	double d;
	B() { d = 8.9; }
};


// û��������������ֻ�Ƕ�����һ������u
union
{
	char c;
	int i;
	double d;
	void show() { cout << c << endl; }
}u = {'U'};


int main()
{
	// ֻ��Ϊunion�ĵ�һ����Ա�ṩ��ʼ��
	A a = {'A'};
	B b;
	cout << a.c << endl;
	cout << b.d << endl;
	a.s.show();
	u.show();

	// ���������еı����������ֲ�����������ͬ�������򼶱�
	// ���������в������г�Ա������������˽�л��߱�����Ա
	// ȫ�����������еĳ�Ա������ȫ�ֻ��߾�̬����
	union
	{
		int p;
		int q;
	};
	p = 3;
	cout << q << endl;

	system("pause");
	return 0;
}