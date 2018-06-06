
// replace_copy()��copy()��replace()����ϣ���Դ����[sourceBeg, sourceEnd)
// �е�Ԫ�ظ��Ƶ���destBegΪ����Ŀ������ȥ��ͬʱ��������oldValue��ȵ�
// ����Ԫ���滻ΪnewValue
// ����Ŀ�������е����һ��������Ԫ�ص���һ��λ�ã�Ҳ���ǵ�һ��δ�����ǵ�Ԫ��λ��
// OutputIterator
// replace_copy(InputIterator sourceBeg, InputIterator sourceEnd,
//				OutputIterator destBeg,
//				const T& oldValue, const T& newValue);

// OutputIterator
// replace_copy_if(InputIterator sourceBeg, InputIterator sourceEnd,
//					OutputIterator destBeg,
//					UnaryPredicate op, const T& newValue);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;
	INSERT_ELEMETNS(coll, 2, 6);
	INSERT_ELEMETNS(coll, 4, 9);
	PRINT_ELEMENTS(coll);

	// print all elements with value 5 replaced with 55
	replace_copy(coll.begin(), coll.end(), 
				ostream_iterator<int>(cout, " "),
				5,
				55);
	cout << endl;

	// print all elements with a value less than 5 replaced with 42
	replace_copy_if(coll.begin(), coll.end(),			// source
					ostream_iterator<int>(cout, " "),	// destination
					bind2nd(less<int>(), 5),			// replacement criterion
					42);								// new value
	cout << endl;

	// print all elements while each odd element is replaced with 0
	replace_copy_if(coll.begin(), coll.end(),
					ostream_iterator<int>(cout, " "),
					bind2nd(modulus<int>(), 2),
					0);
	cout << endl;

	system("pause");
	return 0;
}