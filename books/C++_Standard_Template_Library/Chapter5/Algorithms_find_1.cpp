
#include <iostream>
#include <list>
#include <algorithm>

using std::cout;
using std::endl;
using std::find;
using std::list;
using std::reverse;
using std::max_element;
using std::min_element;


int main()
{
	list<int> coll;
	list<int>::iterator pos;

	for (int i = 20; i <= 40; ++i)
		coll.push_back(i);

	// find position of element with value 3
	// there is none,so pos gets coll.end()
	pos = find(coll.begin(), coll.end(),		// range
				3);								// value

	// reverse the order of elements between found element and the
	// end - because pos is coll.end() it reverses an empty range
	reverse(pos, coll.end());

	// find positions of values 25 and 35
	list<int>::iterator pos25, pos35;
	pos25 = find(coll.begin(), coll.end(), 25);
	pos35 = find(coll.begin(), coll.end(), 35);

	// print the maximum of the corresponding range
	// note: including pos25 but excluding pos35
	cout << "max: " << *max_element(pos25, pos35) << endl;

	// process the elements including the last position
	cout << "max: " << *max_element(pos25, ++pos35) << endl;

	system("pause");
	return 0;
}

