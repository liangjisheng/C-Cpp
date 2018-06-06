// �����޸����͵�const ���� volatile����
// �÷� �� const_cast<type_id>(expression)
// ����ָ�뱻ת���ɷǳ�����ָ�룬������Ȼָ��ԭ���Ķ���
// �������ñ�ת���ɷǳ��������ã�������Ȼָ��ԭ���Ķ���
//const_castһ�������޸ĵ�ָ�롣��const char *p��ʽ��

#include <iostream>

class B
{
public:
	B(int num = 0) : mNum(num) {}
	int mNum;
};

void foo()
{
	const B b1;
	std::cout << b1.mNum << std::endl;
	B* b2 = const_cast<B*>(&b1);
	B& b3 = const_cast<B&>(b1);

	b2->mNum = 1;
	std::cout << b1.mNum << std::endl;
	b3.mNum = 2;
	std::cout << b1.mNum << std::endl;
}

int main()
{
	foo();

	system("pause");
	return 0;
}