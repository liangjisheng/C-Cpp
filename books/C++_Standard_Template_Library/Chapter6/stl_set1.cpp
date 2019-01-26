
#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	/* type of the collection : sets:
	 * no duplicates
	 * elements are integral values
	 * descending order
	*/

	typedef set<int , greater<int> > IntSet;
	IntSet coll1;	// empty set container

	// insert elements in random order 
	coll1.insert(4);
	coll1.insert(3);
	coll1.insert(5);
	coll1.insert(1);
	coll1.insert(6);
	coll1.insert(2);
	coll1.insert(5);
	
	// iterate over all elements and print them
	IntSet::iterator pos;
	for (pos = coll1.begin(); pos != coll1.end(); ++pos)
		cout << *pos << ' ';
	cout << endl;

	// insert 4 again and process return value
	// 如果插入成功，则pair中的iterator返回新插入元素的位置，bool为true
	// 如果原先插入的元素就存在，则pair中的iterator返回插入元素的位置，bool为false
	pair<IntSet::iterator, bool> status = coll1.insert(4);
	if(status.second)
		cout << "4 inserted as element "
			<< distance(coll1.begin(), status.first) + 1 << endl;
	else
		cout << "4 already exists" << endl;

	// assign elements to another set with ascending order
	set<int> coll2(coll1.begin(), coll1.end());

	// print all element of the copy
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements up to element with value 3
	coll2.erase(coll2.begin(), coll2.find(3));

	// print all element
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove all elements with value 5
	int num;
	num = coll2.erase(5);
	cout << num << " element(s) removed" << endl;

	// print all element
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}