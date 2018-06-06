
// heap��һ���ر��Ԫ����֯��ʽ������������:
// 1.��һ��Ԫ���������
// 2.�����ܹ��ڶ���ʱ�������ӻ��Ƴ�һ��Ԫ��
// Ϊ�˴���heap��STL�ṩ�������㷨
// make_heap(),push_heap(),pop_heap(),sort_heap()

// ������[beg, end)�ڵ�Ԫ��ת��Ϊheap
// void make_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void make_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

// ��end֮ǰ�����һ��Ԫ�ؼ���ԭ�����Ǹ�heap��[beg, end - 1)������
// ʹ��������[beg, end)��Ϊһ��heap
// void push_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void push_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

// ������[beg, end)�ڵ����Ԫ�أ�Ҳ���ǵ�һԪ�أ��Ƶ����λ�ã�����ʣ������
// [beg, end - 1)�ڵ�Ԫ����֯��������Ϊһ���µ�heap
// void pop_heap(RandomAccessIterator beg, RandomAccessIterator end);
// void pop_heap(RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op);

// ��[beg, end)�����ڵ�Ԫ��ת��Ϊһ������(sorted)����
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