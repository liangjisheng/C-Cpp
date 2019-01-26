
// 检查若干个值是否存在
// 两种形式都用来判断已序区间[beg, end)是否包含另一个已序区间[searchBeg, searchEnd)
// 的全部元素。对于[searchBeg, searchEnd)中的每一个元素，如果[beg, end)必有一个对应
// 的相当元素，那么[searchBeg, searchEnd)肯定是[beg, end)的子集
// 调用算法之前，必须确保两区间已经按照相同的排序准则拍好序了
// bool includes(InputIterator1 beg, InputIterator end,
//				InputIterator2 searchBeg, InputIterator2 searchEnd);
// bool includes(InputIterator1 beg, InputIterator end,
//				InputIterator2 searchBeg, InputIterator2 searchEnd, BinaryPredicate op);

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	list<int> coll;
	vector<int> search;
	
	INSERT_ELEMETNS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");

	search.push_back(3);
	search.push_back(4);
	search.push_back(7);
	PRINT_ELEMENTS(search, "search: ");

	// check whether all elements in search are also in coll
	if (includes(coll.begin(), coll.end(), search.begin(), search.end()))
		cout << "all element of search are also in coll" << endl;
	else
		cout << "not all element of search are also in coll" <<endl;
	system("pause");
	return 0;
}