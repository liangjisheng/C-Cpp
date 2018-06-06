
// static_cast�൱�ڴ�ͳC�����е���Щ"��Ϊ����"��ǿ������ת�����Ƚ϶��ʹ����
// �������������֮���ת�����������ָ��(����)�����������ָ��(����)֮���ת
// ����һ���ָ���void*���͵�ָ��֮���ת����
// ����������ص��಻����ͨ��static_cast����ת����static_cast���е�ת����һ��
// ��̬ת�������ڱ����Ǿ����ģ�����󣬿ռ��ʵ��Ч��ʵ���ϵȼ���C��ʽǿ��ת��


#include <iostream>

using std::cout;
using std::endl;

class A
{
	char ch;
	int n;
public:
	A(char c, int i) : ch(c), n(i) {}
};


void test_1()
{
	A a('s', 2);
	// char *p = static_cast<char*>(&a);			// invalid type conversion
	// ����ͨ��void*Ϊ�н�ʵ��ת��
	void *q = &a;
	char *p = static_cast<char*>(q);
	cout << *p << endl;

	for(int i = 0; i < sizeof(A); i++)
		cout << (int)p[i] << " ";
	cout << endl;
}


int main()
{
	test_1();

	system("pause");
	return 0;
}