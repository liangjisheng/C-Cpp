
// OutputIterator
// unique_copy(InputIterator sourceBeg, InputIterator sourceEnd,
//				OutputIterator destBeg);
// OutputIterator
// unique_copy(InputIterator sourceBeg, InputIterator sourceEnd,
//				OutputIterator destBeg, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

bool differenceOne(int elem1, int elem2)
{
	return elem1 + 1 == elem2 || elem1 - 1 == elem2;
}

int main()
{
	// source data
	int source[] = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
	int sourceNum = sizeof(source) / sizeof(source[0]);

	list<int> coll;
	copy(source, source + sourceNum, back_inserter(coll));
	PRINT_ELEMENTS(coll);

	// print element with consecutive duplicates removed
	unique_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// print element with consecutive duplicates that differ by one
	unique_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "), differenceOne);
	cout << endl;

	system("pause");
	return 0;
}