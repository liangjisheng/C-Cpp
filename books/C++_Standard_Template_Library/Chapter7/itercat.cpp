
// 下面的程序说明了Random Access 迭代器的特殊能力

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> coll;

	// insert elements from -3 to 9
	for (int i = -3; i <= 9; ++i)
		coll.push_back(i);

	/* print number of elements by processing the distance between beginning and end
	 * NOTE: uses operator - for iterators
	*/
	cout << "number/distance: " << coll.end() - coll.begin() << endl;

	/* print all elements 
	 * NOTE: uses operator < instead of operator !=
	*/
	vector<int>::iterator pos;
	for (pos = coll.begin(); pos < coll.end(); ++pos)
		cout << *pos << " ";
	cout << endl;

	/* print all elements 
	 * NOTE: uses operator[] instead of operator *
	*/
	for (int i = 0; i < coll.size(); ++i)
		cout << coll.begin()[i] << " ";
	cout << endl;

	/* print every second element 
	 * NOTE: uses operator +=
	*/
	for (pos = coll.begin(); pos < coll.end() - 1; pos += 2)
		cout << *pos << " ";
	cout << endl;

	system("pause");
	return 0;
}