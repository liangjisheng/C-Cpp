
#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMETNS(coll1, 1, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");

	// negate all elements in coll1
	transform(coll1.begin(), coll1.end(),	// source range
			coll1.begin(),		// destination range
			negate<int>());		// operation
	PRINT_ELEMENTS(coll1, "coll1: ");

	// transform elements of coll1 into coll2 with ten times their value
	transform(coll1.begin(), coll1.end(),		// source range
			back_inserter(coll2),				// destination range
			bind2nd(multiplies<int>(), 10));	// operation
	PRINT_ELEMENTS(coll2, "coll2: ");

	// print coll2 negatively and in reverse order
	transform(coll2.rbegin(), coll2.rend(),		// source range
		ostream_iterator<int>(cout, " "),		// destination source
		negate<int>());							// operation
	cout << endl;

	system("pause");
	return 0;
}