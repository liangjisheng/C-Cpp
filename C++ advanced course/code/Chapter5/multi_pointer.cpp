
// ��ָ��ָ��������ռ�Ҳ��Ϊ"��̬����"��ֵ��new��������Ķ�̬�ռ䣬��ƽ��˵��
// �������Ǿ�̬���飬���Ĵ�С���ڱ���ʱ���ܾ�̬��������ġ���ά���������Ԫ�ص�
// �ռ�һ���������ģ����ö�̬�ڴ����ķ�ʽ����ռ䣬ֻ����һ��new�����еõ�
// �����Ŀռ�

#include <iostream>

using std::cout;
using std::endl;

void test()
{
	int A[2][3] = {1, 2, 3, 4, 5, 6};
	// pָ�����int[3]���ͣ���ָ�����һ����������
	int (*p)[3];
	int i = 0, j = 0;
	p = new int[2][3];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			p[i][j] = A[i][j];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			cout << (p[i][j] == A[i][j]);
	cout << endl;

	delete []p;

	// ���111111,˵��p��һ����A�Ľṹ��ȫ��ͬ�Ķ�̬��ά����
}


void test_1()
{
	int A[2][3] = {1, 2, 3, 4, 5, 6};
	int **p;
	int i = 0, j = 0;

	p = new int *[2];
	for(i = 0; i < 2; i++)
		p[i] = new int[3];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			p[i][j] = A[i][j];

	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			cout << (p[i][j] == A[i][j]);
	cout << endl;

	for(i = 0; i < 2; i++)
		delete [] p[i];
	delete [] p;
	p = NULL;
}


int main()
{
	test();
	test_1();

	system("pause");
	return 0;
}