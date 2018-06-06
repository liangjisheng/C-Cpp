
// next_permutation()会改变区间[beg, end)内的元素次序，使得他们符合下一个排列次序
// bool next_permutation(BidirectionalIterator beg,
//						BidirectionalIterator end);

// prev_permutation()会改变区间[beg, end)内的元素次序，使得他们符合上一个排列次序
// bool prev_permutation(BidirectionalIterator beg,
//						BidirectionalIterator end);

// 如果元素排列成(就字典顺序而言)正规次序,则两个算法都返回true。所谓正规顺序对
// next_permutation而言为升序，对prev_permutation而言为降序。
// 因此，如果要走遍所有排列，必须先将元素按升序或降序排序，然后循环调用上面两个
// 函数，直到算法返回false

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 3);
	PRINT_ELEMENTS(coll, "on entry: ");

	// permute elements until they are sorted 
	// runs through all permutations because the elements are sorted now
	while (next_permutation(coll.begin(), coll.end()))
		PRINT_ELEMENTS(coll, " ");
	PRINT_ELEMENTS(coll, "afterward: ");
	cout << endl;

	// permute until descending sorted
	// this is the next permutation after ascending sorting
	// so the loop ends immediately
	while (prev_permutation(coll.begin(), coll.end()))
		PRINT_ELEMENTS(coll, " ");
	PRINT_ELEMENTS(coll, "now: ");

	cout << endl;
	// permute elements until they are sorted in descending order
	// runs through all permutations because the elements are sorted
	// in descending order now
	while (prev_permutation(coll.begin(), coll.end()))
		PRINT_ELEMENTS(coll, " ");
	PRINT_ELEMENTS(coll, "afterward: ");

	system("pause");
	return 0;
}