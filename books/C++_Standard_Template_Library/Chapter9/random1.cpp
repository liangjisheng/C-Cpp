
#include "..\..\algostuff.hpp"
#include <cstdlib>
using namespace std;

class MyRandom
{
public:
	ptrdiff_t operator()(ptrdiff_t max)
	{
		double tmp;
		tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		return static_cast<ptrdiff_t>(tmp * max);
	}
};


int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// shuffle all elements randomly
	random_shuffle(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "shuffled: ");

	// sort them again
	sort(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "sorted: ");

	// shuffle elements with self-written random number generator
	// to pass an lvalue we have to use a temporary object
	MyRandom rd;
	random_shuffle(coll.begin(), coll.end(), 
				rd);	// random number generator
	PRINT_ELEMENTS(coll, "shuffled: ");

	system("pause");
	return 0;
}