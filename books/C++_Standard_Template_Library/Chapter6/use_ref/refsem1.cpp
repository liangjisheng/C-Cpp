
// 这个程序说明如何使用CountedPtr

#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include "countptr.hpp"

using namespace std;

void printCountedPtr(CountedPtr<int> elem) 
{ 
	cout << *elem << ' ';
}

int main()
{
	// array of integers (to share in different containers)
	static int values[] = { 3, 5, 9, 1, 6, 4 };

	// two different collections
	typedef CountedPtr<int> IntPtr;
	deque<IntPtr> coll1;
	list<IntPtr> coll2;

	/* insert shared objects into the collections
	 * same order in coll1
	 * reverse order in coll2
	*/
	for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
	{
		IntPtr ptr(new int(values[i]));
		coll1.push_back(ptr);
		coll2.push_front(ptr);
	}

	// print contents of both collections
	for_each(coll1.begin(), coll1.end(), printCountedPtr);
	cout << endl;
	for_each(coll2.begin(), coll2.end(), printCountedPtr);
	cout << endl;

	/* modify values at different places
	 * square third value in coll1
	 * negate first value in coll1
	 * set first value in coll2 to 0
	*/
	*coll1[2] *= *coll1[2];
	(**coll1.begin()) *= -1;
	(**coll2.begin()) = 0;

	// print contents of both collections again
	for_each(coll1.begin(), coll1.end(), printCountedPtr);
	cout << endl;
	for_each(coll2.begin(), coll2.end(), printCountedPtr);
	cout << endl;
	
	system("pause");
	return 0;
}