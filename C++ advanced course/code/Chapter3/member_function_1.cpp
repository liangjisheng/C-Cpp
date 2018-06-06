
// �ⲿ����(��̬����)�ĵ�ַ���Ը���void*ָ�룬����ķǾ�̬��Ա�������У�
// ��ķǾ�̬��Ա�������������������еĴ���Ҫ�޸���Ķ����״̬�����
// �ں�������֮ǰ���������ɸ���Ķ��󣬲��ҽ�����ĵ�ַ���ݸ��ú�����
// ������ķǾ�̬��Ա����������ǰ����������֪��������ڵ�ַ����֪�����
// ���׵�ַ��������Ի�����ķǾ�̬��Ա��������ڵ�ַ����void*��ָ��
// ��ô�Ϳ��Խ�һ����void*�͵�ָ��ת���ɺ���ָ�룬�Ӷ��׿�����ĵ�ַ��
// ֱ�ӵ�����ķǾ�̬��Ա�������������ƻ����������ķ�װ��

#include <iostream>

using std::cout;
using std::endl;

void print() { cout << "External function" << endl; }

class A
{
public:
	void print() { cout << "A's member function" << endl; }
};

typedef void(*func)();


int main()
{
	func p;
	void *v;
	v = (void*)&print;
	p = (func)v;
	p();

	// ���ܽ���ķǾ�̬��Ա�����ĵ�ַת��Ϊvoid*����
	// v = (void*)&A::print;			// error
	// p = (func)v;
	// p();

	system("pause");
	return 0;
}