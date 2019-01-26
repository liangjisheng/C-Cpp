
// �ֲ�����(Partial Sorting)
// ʹ[beg, sortEnd���ڵ�Ԫ�ش�������״̬����sort()��ͬ���ǣ�һ����һ��Ԫ����
// sortEnd֮�������Ԫ�ض����״��򣬾�����ֹͣ
// void partial_sort(RandomAccessIterator beg, RandomAccessIterator sortEnd,
//					RandomAccessIterator end);
// void partial_sort(RandomAccessIterator beg, RandomAccessIterator sortEnd,
//					RandomAccessIterator end, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;

	INSERT_ELEMETNS(coll, 3, 7);
	INSERT_ELEMETNS(coll, 2, 6);
	INSERT_ELEMETNS(coll, 1, 5);
	PRINT_ELEMENTS(coll);

	// sort until the first five elements are sorted
	partial_sort(coll.begin(),		// beginning of the range
				coll.begin() + 5,	// end of sorted range
				coll.end());		// end of full range
	PRINT_ELEMENTS(coll);

	// sort inversely until the first five elements are sorted
	partial_sort(coll.begin(),		// beginning of the range
				coll.begin() + 5,	// end of sorted range
				coll.end(),			// end of full range
				greater<int>());	// sorted criterion
	PRINT_ELEMENTS(coll);

	// sort all elements
	partial_sort(coll.begin(),
				coll.end(),
				coll.end());
	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}