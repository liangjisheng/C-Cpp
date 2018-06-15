
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << "arr: " << endl;
	for (auto i : arr)
		cout << i << ' ';
	cout << endl;

	system("pause");
	return 0;
}