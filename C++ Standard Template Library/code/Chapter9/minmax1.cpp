
// InputIterator min_element(InputIterator beg, InputIterator end);
// InputIterator min_element(InputIterator beg, InputIterator end, CompFunc op);
// InputIterator max_element(InputIterator beg, InputIterator end);
// InputIterator max_element(InputIterator beg, InputIterator end, CompFunc op);

#include <cstdlib>
#include "..\..\algostuff.hpp"
using namespace std;

bool absLess(int elem1, int elem2) { return abs(elem1) < abs(elem2); }

int main()
{
	deque<int> coll;
	INSERT_ELEMETNS(coll, 2, 8);
	INSERT_ELEMETNS(coll, -3, 5);
	PRINT_ELEMENTS(coll);

	// process and print minimum and maximum
	cout << "minimum: "	<< *min_element(coll.begin(), coll.end()) << endl;
	cout << "maximum: " << *max_element(coll.begin(), coll.end()) << endl;

	// process and print minimum and maximum of absolute values
	cout << "minimum of absolute values: "
		<< *min_element(coll.begin(), coll.end(), absLess) << endl;
	cout << "maximum of absolute values: "
		<< *max_element(coll.begin(), coll.end(), absLess) << endl;

	system("pause");
	return 0;
}