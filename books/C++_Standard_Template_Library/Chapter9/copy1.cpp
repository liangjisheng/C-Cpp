
// �����㷨���ǽ�Դ����[sourceBeg, sourceEnd)�е�����Ԫ�ظ�ֵ����destBegΪ���
// ����destEndΪ�յ��Ŀ������ȥ

// OutputIterator
// copy(InputIterator sourceBeg, InputIterator sourceEnd, OutputIterator destBeg);

// BidirectionalIterator1
// copy_backward(BidirectionalIterator1 sourceBeg,
//				BidirectionalIterator1 sourceEnd,
//				BidirectionalIterator2 destEnd);

// STLû��copy_if()�㷨��Ӧ��ʹ��remove_copy_if()���Ʒ���ĳЩ�ض�׼���Ԫ��
// ʹ��reverse_copy()�ڸ��ƹ�������תԪ�ش���
// ʹ�ø�ֵ������������ڵ�����Ԫ�ظ�ֵ����һ����(��������������ͬʱ������ô��)
// ʹ��������assign()��Ա����(�����������Ͳ�ͬʱʹ�ô˷���)

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMETNS(coll1, 1, 9);

	// copy elements of coll1 into coll2
	// use back inserter to insert instead of overwrite
	copy(coll1.begin(), coll1.end(),	// source range
		back_inserter(coll2));			// destination range

	// print elements of coll2
	// copy elements to cout using an ostream iterator
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// copy elements of coll1 into coll2 in reverse order
	// now overwriting
	copy(coll1.rbegin(), coll1.rend(), coll2.begin());

	// print elements of coll2 again
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}