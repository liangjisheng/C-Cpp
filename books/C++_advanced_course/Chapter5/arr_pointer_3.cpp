
#include <iostream>

using std::cout;
using std::endl;

void show1(int A[], int n)
{
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
}

void show2(int A[][5], int n)
{
	for(int i = 0; i < n; i++)
		show1(A[i], 5);
}

void show3(int A[][4][5], int n)
{
	for(int i = 0; i < n; i++)
		show2(A[i], 4);
}


int main()
{
	int d[3][4][5];
	int i, j, k, m = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 5; k++)
				d[i][j][k] = m++;

	// ����һά����,��������int,Ԫ�ظ���60
	show1((int*)d, 3 * 4 * 5);
	cout << endl;

	// ��������Ϊint[5], Ԫ�ظ���12
	show2((int(*)[5])d, 3 * 4);
	cout << endl;

	// ��������Ϊint[4][5], Ԫ�ظ���3
	show3(d, 3);
	cout << endl;


	system("pause");
	return 0;
}