
#include <iostream>

using std::cout;
using std::endl;

template<class T> class B;		// ����BΪһ����ģ��

template<class T> 
class A
{
	T i;
public:
	A() { i = 5; }
	// ��ģ��B��ʵ������������ģ��A�Ĳ���T������һ���ض���ģ����A<t>��˵
	// ֻ��һ��B��ʵ��B<t>��������Ԫ��
	friend class B<T>;			// �������ôд�Ļ���������֮ǰ������
};

template<class T>
class B
{
public:
	static void show(const A<T> &a) { cout << a.i << endl; }
};



template<class T> 
class A1
{
	T i;
public:
	A1() { i = 5; }
	// ����һ���ض�����ģ��A<t>����˵��B���κ�ʵ��B<u>����������Ԫ��
	template<class T1> friend class B1;
};

template<class T>
class B1
{
public:
	// ��ʾʵ������ģ��A1<T>
	static void show(const A1<int> &a) 
	{
		cout << "int" << endl;
		cout << a.i << endl; 
	}
	static void show(const A1<double> &a) 
	{
		cout << "double" << endl;
		cout << a.i << endl; 
	}
};


int main()
{
	A<int> a;
	B<int>::show(a);

	A1<int> a1;
	A1<double> d1;
	B1<int>::show(a1);
	B1<double>::show(a1);
	B1<int>::show(d1);
	B1<double>::show(d1);

	system("pause");
	return 0;
}

