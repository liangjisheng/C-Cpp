
// ����ͨ���������ķ�ʽ�����ķǾ�̬��Ա��������ڵ�ַ

#include <iostream>

using std::cout;
using std::endl;

void print() { cout << "External function" << endl; }

class A
{
public:
	// ���A�е�print()û�з���A�е����ݳ�Ա����ô��������ȡ�˺����ĵ�ַ
	// �ǿ������еģ����print()������A�е����ݳ�Ա���ͻ����������Ǵ���
	void print() { cout << "A's member function" << endl; }
};

typedef void(*func)();


int main()
{
	func p;
	void *v;
	v = (void *)print;
	p = (func)v;
	p();

	_asm{
		lea eax, A::print;
		mov v, eax;
	}
	p = (func)v;
	p();

	system("pause");
	return 0;
}