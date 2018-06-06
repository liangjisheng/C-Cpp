
// ��һ������count��Ԫ��ֵȫ����value��Ԫ��λ��
// InputIterator search_n(InputIterator beg, InputIterator end, Size count, const T& value);
// ��һ������count��Ԫ�����op(elem, value)Ϊtrue��Ԫ��λ��
// �������㷨���������ڵ�STL�淶�У�Ҳû�л�ý����ĶԴ�����ˣ�����ʹ����һ����Ԫ�ж�ʽ
// ����һԪ�ж�ʽ�����ƻ�������STL��һ����
// InputIterator search_n(InputIterator beg, InputIterator end, 
//						Size count, const T& value, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	// find four consecutive elements with value 3
	deque<int>::iterator pos = coll.end();
	pos = search_n(coll.begin(), coll.end(),	// range
					4,	// count
					3);	// value

	// print result
	if (pos != coll.end())
		cout << "four consecutive elements with value 3 "
			<< "start with " << distance(coll.begin(), pos) + 1
			<< ". element" << endl;
	else
		cout << "no four consecutive elements with value 3 found" << endl;


	pos = coll.end();
	// find four consecutive elements with value greater than 3
	pos = search_n(coll.begin(), coll.end(),	// range
					4,					// count
					3,					// value
					greater<int>());	// criterion

	// print result
	if (pos != coll.end())
		cout << "four consecutive elements with value > 3 "
			<< "start with " << distance(coll.begin(), pos) + 1
			<< ". element" << endl;
	else
		cout << "no four consecutive elements with value > 3 found" << endl;

	system("pause");
	return 0;
}