
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

	// 当做一维数组,数据类型int,元素个数60
	show1((int*)d, 3 * 4 * 5);
	cout << endl;

	// 数据类型为int[5], 元素个数12
	show2((int(*)[5])d, 3 * 4);
	cout << endl;

	// 数据类型为int[4][5], 元素个数3
	show3(d, 3);
	cout << endl;


	system("pause");
	return 0;
}