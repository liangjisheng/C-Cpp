
#include <iostream>  

using std::cout;
using std::endl;
using std::cin;

// const_cast��������ֻ�ܽ�const type*����ת����type*���ͣ����߽�
// const_type&ת����type&���ͣ�Զ������Ŀ�����ͳ���const����֮�⣬
// �������������ͬ

// һ������������Ϊֻ������(������),��ô������Զ�ǳ�������const_castȡ����
// �ǶԼ������ʱ�ĸ�д����(��ֻ���ָ�������)�������ܸı���������const����

void ConstTest1()
{
	const int a = 5;
	int *p = NULL;
	p = const_cast<int*>(&a);
	(*p)++;
	// ���Ϊ5��������������a��ֵû�иı䣬���Ǳ��������Ż�����ʱ����a
	// �滻�������ֳ���5.ʵ����a��ֵ�Ѿ������6.
	cout << a << endl << endl;
}

void ConstTest2()
{
	int i = 0;
	cout << "please input a integer:";
	cin >> i;
	const int a = i;
	// ()����ʡ�ԣ�����ֻ��һ������
	int &r = const_cast<int&>(a);
	r++;
	// ����a�޷�ת���ɶ�Ӧ�����ֳ�������������ʾ�����޸�֮���ֵ
	cout << a << endl;
}

int main()
{
	ConstTest1();
	ConstTest2();

	system("pause");
	return 0;
}