
#include <iostream>
using namespace std;

// �����new����Ŀռ���delete[]���ͷţ���ô����ͻ��ڸ����ĵ�ַ��ǰ��Ѱ������
// Ԫ�ظ���(�õ�����һ���ܴ���޷�������)�����н�����޷�Ԥ�ϵģ�����new[]����
// �Ŀռ���delete���ͷţ���delete������Ҫ֪�����ڴ��Ĵ�С��Ϣ�޷���ȷ��ȡ(λ�ò���)
// Ҳ�����ε��ö���������������������еĽ��ͬ�����޷�Ԥ�ϵ�

class A
{
	int i;
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};

int main()
{
	A *pA = new A[3];
	int *p = (int*)pA;
	// ����ռ���׵�ַ֮ǰ����������ĸ���,��ֻ����һ���Ļ����Ͳ�����
	cout << *(p -1) << endl;
	delete []pA;

	pA = new A;
	p = (int*)pA;
	cout << *(p - 1) << endl;
	delete pA;
	cout << endl;

	A *pA1 = new A[3];
	int *p1 = (int*)pA1;
	// ����Ϊ1ֻ���һ���������������
	*(p1 - 1) = 1;
	delete []pA1;

	system("pause");
	return 0;
}