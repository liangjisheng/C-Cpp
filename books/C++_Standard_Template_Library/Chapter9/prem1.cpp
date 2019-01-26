
// next_permutation()��ı�����[beg, end)�ڵ�Ԫ�ش���ʹ�����Ƿ�����һ�����д���
// bool next_permutation(BidirectionalIterator beg,
//						BidirectionalIterator end);

// prev_permutation()��ı�����[beg, end)�ڵ�Ԫ�ش���ʹ�����Ƿ�����һ�����д���
// bool prev_permutation(BidirectionalIterator beg,
//						BidirectionalIterator end);

// ���Ԫ�����г�(���ֵ�˳�����)�������,�������㷨������true����ν����˳���
// next_permutation����Ϊ���򣬶�prev_permutation����Ϊ����
// ��ˣ����Ҫ�߱��������У������Ƚ�Ԫ�ذ������������Ȼ��ѭ��������������
// ������ֱ���㷨����false

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