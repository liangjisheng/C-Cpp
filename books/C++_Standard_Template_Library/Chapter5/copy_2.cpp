
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll1;
	list<int>::iterator iter1;
	vector<int> coll2;
	vector<int>::iterator iter2;

	for (int i = 1; i <= 9; ++i)
		coll1.push_back(i);

	// resize destination to have enough room for the overwriting algorithm
	coll2.resize(coll1.size());

	// copy elements from first into second collection
	// overwrites existing elements in destination
	copy(coll1.begin(), coll1.end(),	// source
			coll2.begin());				// destination

	for (iter2 = coll2.begin(); iter2 != coll2.end(); ++iter2)
		cout << *iter2 << ' ';
	cout << endl;

	// create third collection with enough room
	// initial size is passed as parameter
	deque<int> coll3(coll1.size());
	deque<int>::iterator iter3;

	// copy element from first into third collection
	copy(coll1.begin(), coll1.end(),	// source
			coll3.begin());				// destination

	for (iter3 = coll3.begin(); iter3 != coll3.end(); ++iter3)
		cout << *iter3 << ' ';
	cout << endl;

	system("pause");
	return 0;
}