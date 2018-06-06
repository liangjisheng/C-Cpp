
// 复制时一并移除元素
// OutputIterator
// remove_copy(InputIterator sourceBeg, InputIterator sourceEnd,
//				OutputIterator destBeg, const T& value);
// OutputIterator
// remove_copy_if(InputIterator sourceBeg, InputIterator sourceEnd,
//				OutputIterator destBeg, UnaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll1;
	INSERT_ELEMETNS(coll1, 1, 6);
	INSERT_ELEMETNS(coll1, 1, 9);
	PRINT_ELEMENTS(coll1);

	// print elements without those having the value 3
	remove_copy(coll1.begin(), coll1.end(),
				ostream_iterator<int>(cout, " "),
				3);
	cout << endl;

	// print elements without those having a value greater than 4
	remove_copy_if(coll1.begin(), coll1.end(),			// source
					ostream_iterator<int>(cout, " "),	// destination
					bind2nd(greater<int>(), 4));		// removed elements
	cout << endl;

	// copy all elements greater than 3 into a multiset
	multiset<int> coll2;
	remove_copy_if(coll1.begin(), coll1.end(),
					inserter(coll2, coll2.end()),
					bind2nd(less<int>(), 4));
	PRINT_ELEMENTS(coll2);

	system("pause");
	return 0;
}