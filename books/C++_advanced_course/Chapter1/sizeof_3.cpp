
// ��sizeof����ָ��ʱ������ʲô���͵�ָ�룬��Сһ��Ϊ4(32λƽ̨��)
// ���������ָ������������ڴ�����ռ���ռ�Ĵ�С������ָ��Ҳ������
#include <iostream>

using std::cout;
using std::endl;

char testfunc()
{
	return 'k';
}

int main()
{
	int A[3][5];
	char c[] = "123456";
	int a = 0;
	int *q;
	double* (*d)[3][6];

	// A������������int[3][5]
	cout << sizeof(A) << endl;					// 60

	cout << endl;
	// A[1]������������int[5]
	cout << sizeof(A[0]) << endl;				// 20
	cout << sizeof(A[1]) << endl;				// 20
	cout << sizeof(A[2]) << endl;				// 20
	cout << sizeof(A[3]) << endl;				// 20
	// ����A[4]���±�Խ�磬���������������ʱ������Ϊsizeofֻ������������
	// �����ڱ���׶ξ��Ѿ������
	cout << sizeof(A[4]) << endl;				// 20

	cout << endl;
	// A[0][0]������������int
	cout << sizeof(A[0][0]) << endl;			// 4
	// c������������char[7]
	cout << sizeof(c) << endl;					// 7

	cout << sizeof(a) << endl;					// 4
	cout << sizeof a << endl;					// 4
	cout << sizeof(&testfunc) << endl;			// 4
	// ��testfunc��һ�ε���,����char,����Ϊ1
	cout << sizeof((*testfunc)()) << endl;		// 1

	cout << endl;
	q = new int[10];
	cout << sizeof(q) << endl;					// 4
	cout << sizeof(d) << endl;					// 4
	// sizeof(*d)������������double*[3][6] = 3 * 6 * sizeof(double*) = 72
	cout << sizeof(*d) << endl;					// 72
	// sizeof(**d) = sizeof(double* [6]) = 6 * sizeof(double*) = 24
	cout << sizeof(**d) << endl;				// 24
	// sizeof(***d) = sizeof(double*) = 4
	cout << sizeof(***d) << endl;				// 4
	// sizeof(****d) = sizeof(double) = 8
	cout << sizeof(****d) << endl;				// 8

	system("pause");
	return 0;
}