
// �������(consecutive)��������ϲ�
// ������Դ����[beg1, end1beg2)��[end1beg2, end2)��Ԫ�غϲ���ʹ����[beg1, end2)
// ��Ϊ����֮�ܺ�(���γ�����)
// void inplace_merge(BidirectionalIterator beg1,
//					BidirectionalIterator end1beg2,
//					BidirectionalIterator end2);
// void inplace_merge(BidirectionalIterator beg1,
//					BidirectionalIterator end1beg2,
//					BidirectionalIterator end2,
//					BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;

	// insert two sorted sequences
	INSERT_ELEMETNS(coll, 1, 7);
	INSERT_ELEMETNS(coll, 1, 8);
	PRINT_ELEMENTS(coll);

	// find beginning of second part (element after 7)
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 7);
	++pos;

	// merge into one sorted range
	inplace_merge(coll.begin(), pos, coll.end());

	PRINT_ELEMENTS(coll);

	system("pause");
	return 0;
}