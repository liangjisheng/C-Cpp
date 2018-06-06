
// ��Ѱ��һ��������
// ��������[beg, end)�ں�����[searchBeg, searchEnd)��ȫ�Ǻϵĵ�һ���������ڵ�
// ��һ��Ԫ��λ��
// ForwardIterator1
// search(ForwardIterator1 beg, ForwardIterator1 end,
//			ForwardIterator2 searchBeg, ForwardIterator2 searchEnd);

// ��ӦԪ��ʹ�ö�Ԫ�ж�ʽΪtrue
// ForwardIterator1
// search(ForwardIterator1 beg, ForwardIterator1 end,
//			ForwardIterator2 searchBeg, ForwardIterator2 searchEnd,
//			BinaryPredicate op)

// ��һ�������в���һ��������

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	list<int> subcoll;

	INSERT_ELEMETNS(coll, 1, 7);
	INSERT_ELEMETNS(coll, 1, 7);
	INSERT_ELEMETNS(subcoll, 3, 6);
	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(subcoll, "subcoll: ");

	// search first occurrence of subcoll in coll
	deque<int>::iterator pos = coll.end();
	pos = search(coll.begin(), coll.end(),			// range
				subcoll.begin(), subcoll.end());	// subrange

	// loop while subcoll found as subrange of coll
	while (pos != coll.end())
	{
		// print position of first element
		cout << "subcoll found starting with element "
			<< distance(coll.begin(), pos) + 1 << endl;
		// search next occurrence of subcoll
		++pos;
		pos = search(pos, coll.end(),		// range
					subcoll.begin(), subcoll.end());	// subrange
	}

	system("pause");
	return 0;
}