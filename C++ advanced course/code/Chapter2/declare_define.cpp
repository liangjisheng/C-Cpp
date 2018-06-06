
// ������C++�г��õ�������䣺
// int foo(int, int);				// ����ǰ������
// typedef int Int;					// typedef����
// class bar;						// ��ǰ������
// extern int g_var;				// �ⲿ��������
// friend test;						// ��Ԫ����
// using std::cout;					// ���ֿռ���������

// C++�������Ͷ��������õĶ��������֣���������������������,���԰������ֶ���
// ��Ϊ����Ԫ�أ��������Գ��ֶ�Σ�������ֻ�ܳ���һ��.����һ������Ԫ����֪ͨ
// ��ǰ�������ڴ�������һ������Ԫ��(�Ӷ����ó���Ԫ������������),���ṩ�ó���
// Ԫ�صı�Ҫ��Ϣ(������ȫ��ʵ��ϸ��). ������һ������Ԫ�أ������ṩ�ó���Ԫ��
// �ڵ�ǰ�������ڵ�Ψһ����,��������ʵ��ϸ��


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

extern int i;					// declare
extern int j;					// declare

void greet(string name);

class A;


int main()
{
	cout << i << endl;
	cout << j << endl;
	greet("test");

	// һ���౻������֮�󣬿������������������ı�ʶ��������������������
	// �������Ҳ������ʹ������κγ�Ա
	// A a;					// error
	// a.show();			// error

	system("pause");
	return 0;
}


// ȫ�־�̬�����������Ͷ�����������ͬһ��Դ�ļ��У�
// ��ȫ�ֱ������������Ͷ��������������ڲ�ͬ��Դ�ļ���
int i = 5;						// define
static int j = 6;				// define


static void greet(string name) { cout << "hello " << name << endl; }


// ��A����ȫ�������򣬵��������г�Ա����Ч��Χ�ǴӶ�����ĵط���ʼ��.
// ���ڲ�֪��sizeof(A)�Ĵ�С��Ҳ��֪����Ĺ��캯���Ķ��壬�����ڶ���
// ��A֮ǰ��ʹ��������������ǲ������
class A
{
	int num;
public:
	A() { num = 5; }
	void show() { cout << num << endl; }
};


