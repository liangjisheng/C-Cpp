
#include<iostream>
#include<forward_list>

using std::cout;
using std::endl;
using std::forward_list;

int main()
{
	forward_list<int> arr = { 1, 2, 3, 4, 5, 4, 4 };
	cout << "arr: " << endl;
	for (auto i : arr)
		cout << i << ' ';
	cout << endl;

	arr.remove(4);
	cout << "arr after remove: " << endl;
	for (auto i : arr)
		cout << i << ' ';
	cout << endl;

	system("pause");
	return 0;
}