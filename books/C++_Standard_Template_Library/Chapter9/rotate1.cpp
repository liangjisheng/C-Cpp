
// ��ת�����ڵ�Ԫ��
// ������[beg, end)�ڵ�Ԫ�ؽ�����ת��ִ�к�*newBeg��Ϊ�µĵ�һԪ��
// ����ȷ��newBeg������[beg, end)�ڵ�һ����Чλ�ã���������δ����
// void rotate(ForwardIterator beg, ForwardIterator newBeg,
//				ForwardIterator end);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// rotate one element to the left
	// ֻ�������ȡ���������ܽ����������㣬������������Ҫʹ��advance()
	rotate(coll.begin(),		// beginning of range
			coll.begin() + 1,	// new first element
			coll.end());		// end of range
	PRINT_ELEMENTS(coll, "one left: ");

	// rotate two elements to the right
	rotate(coll.begin(),
		coll.end() - 2,
		coll.end());
	PRINT_ELEMENTS(coll, "two right: ");

	// rotate so that element with value 4 is the beginning
	rotate(coll.begin(),
		find(coll.begin(), coll.end(), 4),
		coll.end());
	PRINT_ELEMENTS(coll, "4 first: ");

	system("pause");
	return 0;
}