
#include <algorithm>
#include <functional>
#include "carray.hpp"
#include "..\..\print.hpp"

using namespace std;

int main()
{
	carray<int, 10> a;
	for (std::size_t i = 0; i < a.size(); ++i)
		a[i] = i + 1;
	
	PRINT_ELEMENTS(a);
	cout << endl;

	reverse(a.begin(), a.end());
	PRINT_ELEMENTS(a);
	cout << endl;

	transform(a.begin(), a.end(),		// source
				a.begin(),				// destination
				negate<int>());			// operation

	PRINT_ELEMENTS(a);
	cout << endl;

	system("pause");
	return 0;
}