
#include "..\..\algostuff.hpp"
using namespace std;

// checks whether an element is even or odd
bool checkEven(int elem, bool even)
{
	if (even)
		return elem % 2 == 0;
	else
		return elem % 2 == 1;
}


int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// arguments for checkEven()
	// check for "even odd even"
	// 找出三个满足偶，奇，偶条件的子序列
	bool checkEvenArgs[3] = { true, false, true };

	// search first subrange in coll
	vector<int>::iterator pos = coll.end();
	pos = search(coll.begin(), coll.end(),			// range
				checkEvenArgs, checkEvenArgs + 3,	// subrange values
				checkEven);							// subrange criterion

	// loop while subrange found
	while (pos != coll.end())
	{
		// print position of first element
		cout << "subrange found starting with element "
			<< distance(coll.begin(), pos) + 1 << endl;

		// search next subrange in coll
		pos = search(++pos, coll.end(),		// range
					checkEvenArgs, checkEvenArgs + 3,	// subrange
					checkEven);				// subrange criterion
	}

	system("pause");
	return 0;
}