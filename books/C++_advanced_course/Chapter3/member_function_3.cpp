
// VC++�У���ĳ�Ա�����ڵ���֮ǰ�����������ɵĻ����뽫������׵�ַ����
// �Ĵ���ecx��������ͨ�������������ȡ����ķǾ�̬��Ա��������ڵ�ַ
// �ڵ��ú���֮ǰ����Ӧ�ý��������׵�ַ����Ĵ���ecx�У���֤��ȷ�ĵ���

#include <iostream>

using std::cout;
using std::endl;

typedef void(*func)();


class A
{
	int i;
public:
	A() { i = 5; }
	void print() { cout << i << endl; }
};

void Invoke(A& a)
{
	func p;
	_asm{
		lea eax, A::print			// ��A�е�print�ĵ�ַ����eax�Ĵ�����
		mov p, eax					// ��eax�Ĵ����е�ֵ����p
		// ȥ����������������ʱ�׳��쳣,�ڴ�ķǷ�����
		mov ecx, a					// �������ַ����ecx�Ĵ���
	}
	p();
}

void Invoke1(A a)
{
	func p;
	_asm{
		lea eax, A::print
		mov p, eax
		// �����ڶ�ջ�ϵ�ʵ�εĸ����ĵ�ַ����Ĵ���ecx��
		lea ecx, a
	}
	p();
}


int main()
{
	A a;
	Invoke(a);
	Invoke1(a);

	system("pause");
	return 0;
}