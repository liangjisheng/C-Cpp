
// �ڳ����ж���ͷ�ͬһ���ڴ棬����һ����������������д���Ҳ��һ����
// ���³��������Ǳ������������ı�����ʵ���йأ����Ƕ���ͷ�ͬһ���ڴ�
// �ռ������һ����̴������������ܻ�������ĳ��ʱ�̵��������߼�����
// �ķ��ͣ��Ӷ�������ĵ��Ժ;����������

#include <iostream>

using namespace std;

int main()
{
	int *p, *q, *one;

	one = new int;
	if(one)
		cout << one << endl;
	delete one;

	// ��ָ��one��ָ��Ŀռ��ͷ�֮��p����Ŀռ����ԭ��one��ָ��ĵ�Ԫ
	p = new int(3);
	if(p)
		cout << p  << endl;
	delete one;		// �൱��delete p

	// delete one֮��p����Ŀռ����ԭ��one��ָ��ĵ�Ԫ��Ҳ��p��ָ��ĵ�Ԫ
	q = new int(5);
	if(q)
		cout << q << endl;
	cout << (*p) + (*q) << endl;		// 10
	delete p;
	// delete q;		// ��ʱp��q��ָ����ͬ�ĵ�ַ,����delete����

	system("pasue");
	return 0;
}

