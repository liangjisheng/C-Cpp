
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int A[4] = {1, 2, 3, 4};
	int B[4] = {5, 6, 7, 8};
	int (&rA)[4] = A;

	cout << A << endl;
	cout << &A << endl;
	cout << A + 1 << endl;
	cout << &A + 1 << endl;
	cout << B << endl;
	cout << rA << endl;
	cout << &rA << endl;

	// ��������������A��&A����ֵ������ȵģ���A������������int[4],��һ��
	// ָ�볣���� int *const,��&A������������int(*)[4],�����ڸ������ǲ�ͬ��
	// ��ֱ�ӵ�����A+1��&A+1�Ľ����ȫ��ͬ��A+1����A���׵�ַ����sizeof(int)
	// ��&A+1����ֵ�ϵ���A���׵�ַ����sizeof(A),rA�Ƕ�����A������

	system("pause");
	return 0;
}