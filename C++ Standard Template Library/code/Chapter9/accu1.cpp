
// 对序列进行某种运算
// 如果beg == end则两者都返回initValue
// 返回initValue + elem1 + elem2 + elem3 + ...
// T accumulate(InputIterator beg, InputIterator end, T initValue);
// 返回initValue op elem1 op elem2 op elem3
// T accumulate(InputIterator beg, InputIterator end, T initValue, BinaryFunc op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	// process sum of elements
	cout << "sum: " << accumulate(coll.begin(), coll.end(), 0) << endl;

	// process sum of elements less 100
	cout << "sum: " << accumulate(coll.begin(), coll.end(), -100) << endl;

	// process product of elements
	cout << "product: " << accumulate(coll.begin(), coll.end(), 1, multiplies<int>()) << endl;

	// process product of elements (use 0 as initial value)
	cout << "product: " << accumulate(coll.begin(), coll.end(), 0, multiplies<int>()) << endl;

	system("pause");
	return 0;
}