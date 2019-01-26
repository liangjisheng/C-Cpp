
// heap是一种特别的元素组织方式，有两大性质:
// 1.第一个元素总是最大
// 2.总是能够在对数时间内增加或移除一个元素
// 为了处理heap，STL提供了四种算法
// make_heap(),push_heap(),pop_heap(),sort_heap()

// 将区间[beg, end)内的元素转换为heap
// void make_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void make_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

// 将end之前的最后一个元素加入原本就是个heap的[beg, end - 1)区间内
// 使整个区间[beg, end)成为一个heap
// void push_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void push_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

// 将区间[beg, end)内的最高元素，也就是第一元素，移到最后位置，并将剩余区间
// [beg, end - 1)内的元素组织起来，成为一个新的heap
// void pop_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void pop_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

// 将[beg, end)区间内的元素转换为一个以序(sorted)序列
// void sort_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void sort_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	INSERT_ELEMETNS(coll, 3, 7);
	INSERT_ELEMETNS(coll, 5, 9);
	INSERT_ELEMETNS(coll, 1, 4);
	PRINT_ELEMENTS(coll, "on entry: ");

	// convert collection into a heap
	make_heap(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "after make_heap(): ");

	// pop next element out of the heap
	pop_heap(coll.begin(), coll.end());
	coll.pop_back();
	PRINT_ELEMENTS(coll, "after pop_heap(): ");

	// push new element into the heap
	coll.push_back(17);
	push_heap(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "after push_heap(): ");

	// convert heap into a sorted collection
	// note: after the call it is no longer a heap
	sort_heap(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "after sort_heap(): ");

	system("pause");
	return 0;
}