
// 将区间[beg, end)内的每一个元素都赋予新值newValue
// void fill(ForwardIterator beg, ForwardIterator end, const T& newValue);

// 从beg开始的前num个元素赋予新值newValue
// void fill_n(OutputIterator beg, Size num, const T& newValue);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	// print ten times 7.7
	fill_n(ostream_iterator<float>(cout, " "),	// beginning of destination
		10,				// count
		(float)7.7);	// newValue
	cout << endl;

	list<string> coll;

	// insert "hello" nine times
	fill_n(back_inserter(coll), 9, "hello");
	PRINT_ELEMENTS(coll, "coll: ");

	// overwrite all elements with again
	fill(coll.begin(), coll.end(), "again");
	PRINT_ELEMENTS(coll, "coll: ");

	// replace all but two elements with "hi"
	fill_n(coll.begin(), coll.size() - 2, "hi");
	PRINT_ELEMENTS(coll, "coll: ");

	// replace the second and up to the last element but one with "hmmm"
	list<string>::iterator pos1, pos2;
	pos1 = coll.begin();
	pos2 = coll.end();
	fill(++pos1, --pos2, "hmmm");
	PRINT_ELEMENTS(coll, "coll: ");

	system("pause");
	return 0;
}