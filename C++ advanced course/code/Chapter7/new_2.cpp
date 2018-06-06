
#include <iostream>
using namespace std;

// ʹ��new��new[]����ռ�ʱ��ϵͳ����Ҫ������Ŀռ��С֮���������һ��ռ�
// ���ڷ��ظ��û��Ŀռ��ǰ�棬���������û�����ռ���ֽ������������ĸ���
// ����Ϣ��PrintContent()�����ڸ�����ַ�ռ䴦���������ɸ�����(int)�����Ŀռ�
// Ȼ���⼸��ֵ���

// ����new����ռ�ʱ������ֻ��Ҫ��delete�ͷſռ�����ˣ������漰��ε��ñ��ͷ�
// �Ķ�����������������⣬���Բ��ô������Ԫ�صĸ������۲�������ڷ��ص�ַ��
// ���˵�4��������ŵ��û�����Ŀռ���ֽ���
// ����new[]����ռ�ʱ�����ݱ����������������͵ľ�������������ְ��ţ�
// ���������ǻ����������͵����ݣ�������Ȼ������������͵����ݣ������ͷŵ�ʱ��
// ������Ҫ������������(��class A)��ô�������Ϣ����˳������new��������ʱ��ͬ
// �������������������ݣ��������ͷŵ�ʱ����Ҫ������������(��class B)����ô��
// ���ص�ַ�����˵�5��������ŵ��û�����ռ���ֽ���(�ڼ�4����4���ֽ���������
// ���ݵ������Ϊ�ָ����)���ڵ��˵�1��������Ŷ�̬����Ԫ�صĸ���

void PrintContent(void *addr, int offset)
{
	char *s = (char*)addr;
	int *p = (int*)(s - offset * 4);
	for(int i = 0; i < offset; i++)
		cout << p[i] << " ";
	cout << endl;
}

class A
{
	char c[10];
};

class B
{
	char c[10];
public:
	~B() {}
};


int main()
{
	int *p = new int[5];
	PrintContent(p, 5);
	delete []p;

	char *s = new char[100];
	PrintContent(s, 5);
	delete []s;

	double *q = new double;
	PrintContent(q, 5);
	delete q;

	A *a1 = new A;
	PrintContent(a1, 5);
	delete a1;

	A *a2 = new A;
	PrintContent(a2, 5);
	delete a2;

	B *b1 = new B;
	PrintContent(b1, 5);
	delete b1;

	B *b2 = new B[5];
	PrintContent(b2, 5);
	delete []b2;

	system("pause");
	return 0;
}