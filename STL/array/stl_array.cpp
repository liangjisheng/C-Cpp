
#include<iostream>
#include<array>

using std::cout;
using std::endl;
using std::array;

int main()
{
	array<int, 4> arr = { 1, 2, 3, 4 };
	cout << "arr: " << endl;
	for (auto i : arr)
		cout << i << ' ';
	cout << endl;

	int nSize = sizeof(arr);
	cout << "arr size: " << nSize << endl;

	system("pause");
	return 0;
}