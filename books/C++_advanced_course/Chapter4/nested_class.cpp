
// �����������ϵ���ϵ֮�⣬��ʵ��Χ����Ƕ������������ȫ�������࣬��û������
// ����Ĺ�ϵ��Ҳ����˵��Ƕ����ĳ�Ա����Χ��ĳ�Աû���κι�ϵ�����ǲ��ܹ�
// �໥���ʣ�Ҳ��������Ԫ�Ĺ�ϵ

#include <iostream>

using std::endl;
using std::cout;

class A
{
public:
	class B
	{
	public:
		B(char *name) 
		{ cout << "Constructing B:" << name << endl; }
	};
	B b;
	A() : b("In class A") 
	{ cout << "Constructing A" << endl; }
};


int main()
{
	A a;
	A::B b("Outside class A");

	system("pause");
	return 0;
}