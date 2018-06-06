
// 元素计数
// 返回在区间内元素值等于value的元素个数
// difference_type count(InputIterator beg, InputIterator end, const T& value)
// 返回另一元判断式为true的元素个数
// difference_type count_if(InputIterator beg, InputIterator end, UnaryPredicate op)
// 关联式容器提供了一个等效的成员函数count()，用来计算某个value或某个key的元素个数

#include "..\..\algostuff.hpp"
using namespace std;

bool isEven(int elem) { return elem % 2 == 0; }

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	// count and print elements with value 4
	int num = count(coll.begin(), coll.end(), 4);
	cout << "number of elements equal to 4: " << num << endl;

	// count elements with even value
	num = count_if(coll.begin(), coll.end(), // range
		isEven);		// criterion
	cout << "number of elements with even values: " << num << endl;

	num = count_if(coll.begin(), coll.end(),
					not1(bind2nd(modulus<int>(), 2)));
	cout << "number of elements with even values: " << num << endl;

	// count elements that are greater than value 4
	num = count_if(coll.begin(), coll.end(),		// range
					bind2nd(greater<int>(), 4));	// criterion
	cout << "number of elements greater than 4: " << num << endl;

	system("pause");
	return 0;
}