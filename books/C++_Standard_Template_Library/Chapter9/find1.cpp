
// InputIterator find(InputIterator beg, InputIterator end, const T& value);
// InputIterator find_if(InputIterator, beg, InputIterator end, UnaryPredicate op);
// 关联式容器提供了一个等效的成员函数find(),拥有对数复杂度，而非线性复杂度

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// find first element with value 4
	list<int>::iterator pos1 = coll.end();
	pos1 = find(coll.begin(), coll.end(), 4);

	// find second element with value 4
	// note: continue the search behind the first 4 (if any)
	list<int>::iterator pos2 = coll.end();
	if (pos1 != coll.end())
		pos2 = find(++pos1, coll.end(), 4);

	/* print all elements from first to second 4 (both included)
	 * note: now we need the position of the first 4 again (if any)
	 * note: we have to pass the position behind the second 4 (if any)
	*/
	if (pos1 != coll.end() && pos2 != coll.end())
	{
		copy(--pos1, ++pos2, ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	system("pause");
	return 0;
}