
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	const int i = 0;
	int *j = (int *)&i;
	*j = 1;
	cout << "i = " << i << endl;
	cout << "*j = " << *j << endl;

	system("pause");
	return 0;
}
