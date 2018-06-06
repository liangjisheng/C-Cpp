
// copy()��rotate()�����
// OutputIterator
// rotate(ForwardIterator sourceBeg, ForwardIterator newBeg,
//		ForwardIterator sourceEnd,
//		OutputIterator destBeg);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	set<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	// print elements rotated one element to the left
	set<int>::iterator pos = coll.begin();
	// ��������posָ����һ��λ�ã���pos���������ȡ��������ֻ��ʹ���������
	advance(pos, 1);
	rotate_copy(coll.begin(),
				pos,
				coll.end(),
				ostream_iterator<int>(cout, " "));
	cout << endl;

	// print elements rotated two elements to the right
	pos = coll.end();
	advance(pos, -2);
	rotate_copy(coll.begin(),
				pos,
				coll.end(),
				ostream_iterator<int>(cout, " "));
	cout << endl;

	// print elements rotated so that element with value 4 is the beginning
	rotate_copy(coll.begin(),
				coll.find(4),	// ��Ա����find()��find()�㷨���и��õ�����
				coll.end(),
				ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}