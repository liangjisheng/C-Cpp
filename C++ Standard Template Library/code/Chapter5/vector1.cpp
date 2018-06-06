
#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> coll;

	// append elements with values 1 to 6
	for (int i = 1; i <= 6; ++i)
		coll.push_back(i);

	// print all elements followed by a space
	for (unsigned int i = 0; i < coll.size(); ++i)
		cout << coll[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}