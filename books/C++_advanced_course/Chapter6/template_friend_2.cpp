
#include <iostream>

using std::cout;
using std::endl;


// ����Ԫ��������Ϊһ��ʹ����ģ�������ͨ����
template<typename T>
class A
{
	int i ;
	friend void show(const A<T> &a) { cout << a.i << endl; }
public:
	A() { i = 5; }
};


// ����Ԫ��������Ϊһ��ʹ����ģ����ĺ���ģ��
template<typename T>
class A1
{
	int i ;
	template<typename T>
	friend void show1(const A1<T> &a) { cout << a.i << endl; }
public:
	A1() { i = 5; }
};

// �����ǽ���Ԫ����Ϊ��ͨ�������Ǻ���ģ�壬���ڽ���Ԫ����ֱ�Ӷ�������ģ������
// ���Բ�����������Ͷ���֮��Ĳ�һ��


// ����Ԫ��������Ϊһ��ʹ����ģ����ĺ���ģ��,��ģ��Ķ��������ģ������
template<typename T>
class A2
{
	int i ;
	template<typename T>
	friend void show2(const A2<T> &a);
public:
	A2() { i = 5; }
};

template<typename T>
void show2(const A2<T> &a) { cout << a.i << endl; }


template<typename T>
class A3
{
	int i ;
	template<typename T1>
	friend void show3(const A3<T1> &a);
public:
	A3() { i = 5; }
};

template<typename T1>
void show3(const A3<T1> &a) { cout << a.i << endl; }


// ����A4<T>Ϊһ����ģ��
template<typename T> class A4;
// ��ǰ��show4()����Ϊһ������ģ��
template<typename T> void show4(const A<T>&);

template<typename T>
class A4
{
	T i;
	// ����ģ��A4<T>��ʹ����ʾģ��������﷨����Ԫ��������
	friend void show4<T>(const A4<T> &a);
public:
	A4() { i = T(5); }
};

template<typename T>
void show4(const A4<T> &a) { cout << a.i << endl; }


int main()
{
	// show()������ģ����A<int>����Ԫ����
	A<int> a;
	show(a);

	// show1()���ò������������ݣ�����ģ�庯��show1<int>(),�ú���
	// ��ģ����A1<int>����Ԫ����
	A1<int> a1;
	show1(a1);

	// show2()����ʱ���Ͳ������ݣ�������ģ�庯��show2<int>(),�ú���
	// ��ģ����A2<int>����Ԫ����
	A2<int> a2;
	show2(a2);

	// show3()����ʱ���Ͳ������ݣ�������ģ�庯��show3<int>(),�ú���
	// ��ģ����A3<int>����Ԫ����
	A3<int> a3;
	show3(a3);

	// ��ģ��A4<T>��ʵ����ΪA4<int>�Ĺ����У�����������Ϊ�ɺ���ģ��show4<T>
	// ���ɵ�ģ�庯��show4<int>��ģ����A4<int>����Ԫ�������Ӷ���show4(a4)
	// ��ʱ����������ģ��show<T>��ʵ����
	A4<int> a4;
	show4(a4);

	system("pause");
	return 0;
}

