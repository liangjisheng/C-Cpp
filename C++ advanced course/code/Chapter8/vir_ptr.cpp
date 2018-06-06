
// ��̬����ָ������������ڵ�ַ��������ʱ���������ڱ���ʱ������.C++���ö�̬����������麯��
// �ĵ���,C++��û�й涨���ʵ�ֶ�̬����,���������C++����������ͨ����ָ��(vptr)���麯����
// (vtable)��ʵ�ֶ�̬�����.����˼·��:Ϊÿһ�������麯�����ཨ��һ���麯�����麯�����
// ���������ŵ��Ǹ��麯�����ڴ��е���ڵ�ַ;�ڸ����ÿ������������һ��ָ���麯�����ָ��
// �ڵ��ú���ʱ,�������麯���ҵ��麯����,ȷ���麯������ڵ�ַ�ڱ��е�λ��,��ȡ��ڵ�ַ���
// ����.
// ��ָ����Ϊ�����һ���ִ���ڶ���Ŀռ���.һ����ֻ��һ���麯����,��˸�������Զ����е�
// ��ָ�붼ָ��ͬһ���ط�.�ڲ�ͬ�ı�������,��ָ���ڶ����е�λ���ǲ�ͬ��.���ֵ��͵�������
// ��Visual C++�У���ָ��λ�ڶ������ʼλ��;��GNU C++��,��ָ��λ�ڶ����β��������ͷ��
// ��ͨ������ĳ��򿼲���Visual C++����ָ���ڶ����е�λ��

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::hex;

int globalv = 0;

class NoVirtual
{
	int i;
public:
	void func() { cout << "No Virtual Function" << endl; }
	NoVirtual() { i = ++globalv; }
};

class HaveVirtual : public NoVirtual
{
public:
	virtual void func() { cout << "Virtual Function" << endl; }
};


int main()
{
	NoVirtual n1, n2;
	HaveVirtual h1, h2;
	unsigned long *p;

	cout << "sizeof(NoVirtual) is :" << sizeof(NoVirtual) << endl;
	cout << "sizeof(HaveVirtual) is :" << sizeof(HaveVirtual) << endl;
	p = reinterpret_cast<unsigned long*>(&n1);
	cout << "the content of first 4 bytes of n1 is :" << p[0] << endl;
	p = reinterpret_cast<unsigned long*>(&n2);
	cout << "the content of first 4 bytes of n2 is :" << p[0] << endl;

	// ͷ4�ֽڴ�ŵ����麯�������ڵĵ�ַ
	p = reinterpret_cast<unsigned long*>(&h1);
	cout << "the content of first 4 bytes of h1 is :0x" << hex << p[0] << endl;
	p = reinterpret_cast<unsigned long*>(&h2);
	cout << "the content of first 4 bytes of h2 is :0x" << hex << p[0] << endl;

	system("pause");
	return 0;
}