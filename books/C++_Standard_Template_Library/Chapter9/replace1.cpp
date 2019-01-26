
// void replace(ForwardIterator beg, ForwardIterator end,
//				const T& oldValue, const T& newValue);
// void replace_if(ForwardIterator beg, ForwardIterator end,
//					UnaryPredicate op, const T& newValue);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;

	INSERT_ELEMETNS(coll, 2, 7);
	INSERT_ELEMETNS(coll, 4, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// replace all elements with value 6 with 42
	replace(coll.begin(), coll.end(), 6, 42);
	PRINT_ELEMENTS(coll, "coll: ");

	// replace all elements with value less than 5 with 0
	replace_if(coll.begin(), coll.end(),	// range
				bind2nd(less<int>(), 5),	// criterion for replacement
				0);		// new value
	PRINT_ELEMENTS(coll, "coll: ");

	system("pause");
	return 0;
}