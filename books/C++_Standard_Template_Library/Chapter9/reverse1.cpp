
// void reverse(BidirectionalIterator beg, BidirectionalIterator end);
// OutputIterator reverse_copy(BidirectionalIterator sourceBeg, 
//			BidirectionalIterator sourceEnd, OutputIterator destBeg);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// reverse order of elements
	reverse(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "coll: ");

	// reverse order from second to last element but one
	reverse(coll.begin() + 1, coll.end() - 1);
	PRINT_ELEMENTS(coll, "coll: ");

	// print all of them in reverse order
	reverse_copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}