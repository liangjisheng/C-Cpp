
#include <iostream>

using namespace std;

typedef int* pInt;

int main()
{
	int i = 2, j = 3;
	int* p1,p2;
	pInt q1, q2;
	p2 = 4;
	p1 = &p2;
	q1 = &i;
	q2 = &j;

	cout << *q1 << " " << *q2 << " " << *p1 << endl;

	system("pause");
	return 0;
}