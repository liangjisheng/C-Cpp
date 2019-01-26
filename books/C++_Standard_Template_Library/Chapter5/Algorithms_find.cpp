
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::find;
using std::min_element;
using std::max_element;
using std::reverse;


int main()
{
	vector<int> coll;
	vector<int>::iterator iter;

	coll.push_back(2);
	coll.push_back(5);
	coll.push_back(4);
	coll.push_back(1);
	coll.push_back(6);
	coll.push_back(3);

	// print
	cout << "output all elements: " << endl;
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	// find and print minimum and maximum elements
	iter = min_element(coll.begin(), coll.end());
	cout << "min: " << *iter << endl;
	iter = max_element(coll.begin(), coll.end());
	cout << "max: " << *iter << endl;

	// sort all elements
	sort(coll.begin(), coll.end());

	cout << "output all elements: " << endl;
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	// find the first element with value 3
	iter = find(coll.begin(), coll.end(),			// range
				3);									// value
	// reverse the order of the found element with value 3 
	// and all following elements
	reverse(iter, coll.end());

	cout << "output all elements: " << endl;
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	system("pause");
	return 0;
}

