
// 检验小于
// 判断区间[beg1, end1)的元素是否小于区间[beg2, end2)的元素，所谓小于是
// 指字典(lexicographical)顺序的意义
// 对两个序列中的元素一一比较，直到以下情况发生：
// 如果两元素不相等，则这两个元素的比较结果就是整个两序列的比较结果
// 如果两序列中的元素数量不同，则元素较少的那个序列小于另一序列，所以如果
// 第一序列的元素数量较少，比较结果是true
// 如果两个序列都没有更多的元素可做比较，则这两个序列相等，整个比较结果是false

// bool lexicographical_compare(InputIterator1 beg1, InputIterator1 end1,
//								InputIterator2 beg2, InputIterator2 end2);

// bool lexicographical_compare(InputIterator1 beg1, InputIterator1 end1,
//								InputIterator2 beg2, InputIterator2 end2,
//								CompFunc op);

#include "..\..\algostuff.hpp"
using namespace std;

void pritnCollection(const list<int>& l) { PRINT_ELEMENTS(l); }

bool lessForCollection(const list<int>& l1, const list<int>& l2)
{
	return lexicographical_compare(
		l1.begin(), l1.end(),	// first range
		l2.begin(), l2.end());	// second range
}


int main()
{
	list<int> c1, c2, c3, c4;

	// fill all collections with the same starting values
	INSERT_ELEMETNS(c1, 1, 5);
	c4 = c3 = c2 = c1;

	// and now some differences
	c1.push_back(7);
	c3.push_back(2);
	c3.push_back(0);
	c4.push_back(2);

	// create collection of collections
	vector<list<int> > cc;

	cc.push_back(c1);
	cc.push_back(c2);
	cc.push_back(c3);
	cc.push_back(c4);
	cc.push_back(c3);
	cc.push_back(c1);
	cc.push_back(c4);
	cc.push_back(c2);

	// print all collections
	for_each(cc.begin(), cc.end(), pritnCollection);
	cout << endl;

	// sort collection lexicographically
	sort(cc.begin(), cc.end(), lessForCollection);

	// print all collections
	for_each(cc.begin(), cc.end(), pritnCollection);

	system("pause");
	return 0;
}