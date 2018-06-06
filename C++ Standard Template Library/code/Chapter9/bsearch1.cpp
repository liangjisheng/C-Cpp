
#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;

	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	// check existence of element with value 5
	if (binary_search(coll.begin(), coll.end(), 5))
		cout << "5 is present" << endl;
	else
		cout << "5 is not present" << endl;

	// check existence of element with value 42
	if (binary_search(coll.begin(), coll.end(), 42))
		cout << "42 is present" << endl;
	else
		cout << "42 is not present" << endl;

	system("pause");
	return 0;
}