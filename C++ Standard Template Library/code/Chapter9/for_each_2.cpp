
#include "..\..\algostuff.hpp"

using namespace std;

// function object that adds the value with which it is initialized
template<class T>
class AddValue
{
private:
	T theValue;		// value to add
public:
	AddValue(const T& v) : theValue(v) {}

	// the function call for the element adds the value
	void operator() (T& elem) const { elem += theValue; }
};

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);

	// add ten to each element
	for_each(coll.begin(), coll.end(), AddValue<int>(10));
	PRINT_ELEMENTS(coll);

	// add value of first element to each element
	for_each(coll.begin(), coll.end(), AddValue<int>(*coll.begin()));
	PRINT_ELEMENTS(coll);

	vector<int> coll1;
	INSERT_ELEMETNS(coll1, 1, 9);

	transform(coll1.begin(), coll1.end(),
		coll1.begin(),
		bind2nd(plus<int>(), 10));
	PRINT_ELEMENTS(coll1);

	transform(coll1.begin(), coll1.end(),
		coll1.begin(),
		bind2nd(plus<int>(), *coll1.begin()));
	PRINT_ELEMENTS(coll1);

	system("pause");
	return 0;
}