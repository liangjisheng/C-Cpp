
// 第一组连续count个元素值全等于value的元素位置
// InputIterator search_n(InputIterator beg, InputIterator end, Size count, const T& value);
// 第一组连续count个元素造成op(elem, value)为true的元素位置
// 这两个算法并不在早期的STL规范中，也没有获得谨慎的对待，因此，下面使用了一个二元判断式
// 而非一元判断式，这破坏了早期STL的一致性
// InputIterator search_n(InputIterator beg, InputIterator end, 
//						Size count, const T& value, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	// find four consecutive elements with value 3
	deque<int>::iterator pos = coll.end();
	pos = search_n(coll.begin(), coll.end(),	// range
					4,	// count
					3);	// value

	// print result
	if (pos != coll.end())
		cout << "four consecutive elements with value 3 "
			<< "start with " << distance(coll.begin(), pos) + 1
			<< ". element" << endl;
	else
		cout << "no four consecutive elements with value 3 found" << endl;


	pos = coll.end();
	// find four consecutive elements with value greater than 3
	pos = search_n(coll.begin(), coll.end(),	// range
					4,					// count
					3,					// value
					greater<int>());	// criterion

	// print result
	if (pos != coll.end())
		cout << "four consecutive elements with value > 3 "
			<< "start with " << distance(coll.begin(), pos) + 1
			<< ". element" << endl;
	else
		cout << "no four consecutive elements with value > 3 found" << endl;

	system("pause");
	return 0;
}