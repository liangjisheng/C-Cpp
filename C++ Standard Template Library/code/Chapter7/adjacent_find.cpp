

/***********************************************************
 * @brief: adjacent_find
 * @author: Jisheng Liang
 * @email: 1294851990@qq.com
 * @date: 2017/12/20 15:58:06
 * @version: 1.0
 **********************************************************/

/* adjacent_find用于查找相等或满足条件的邻近元素对。有两个函数原型: 一种是在迭代器区间
 * [first, last)上查找两个连续的元素相等时，返回元素对中的第一个元素的迭代器位置。
 * 另一种是使用二元谓词判断binary_pred,查找迭代器区间[first, last)上满足条件binary_pred
 * 条件的邻近元素对，未找到返回last
*/

/**
template<class ForwardIterator>
	ForwardIterator adjacent_find(
	ForwardIterator _First,
	ForwardIterator _Last
	);  
template<class ForwardIterator , class BinaryPredicate>  
	ForwardIterator adjacent_find(  
	ForwardIterator _First,   
	ForwardIterator _Last,   
	BinaryPredicate _Comp  
	);
*/


#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

// 判断x和y是否奇偶同性
bool parity_equal(int x, int y) 
{
	return abs(x - y) % 2 == 0 ? 1 : 0;
}

int main()
{
	list<int> coll;
	coll.push_back(3);
	coll.push_back(6);
	coll.push_back(9);
	coll.push_back(11);
	coll.push_back(11);
	coll.push_back(18);
	coll.push_back(20);
	coll.push_back(20);

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 查找邻接相等的元素
	list<int>::iterator iter = adjacent_find(coll.begin(), coll.end());
	if (iter != coll.end())
	{
		cout << "链表中第一对相等的相邻元素为: " << endl;
		cout << *iter++ << " " ;
		cout << *iter << endl;
	}
	else
		cout << "链表中没有相等的相邻元素" << endl;

	// 查找奇偶同性的相邻元素
	iter = adjacent_find(coll.begin(), coll.end(), parity_equal);
	if (iter != coll.end())
	{
		cout << "链表中第一对奇偶同性的相邻元素为： " << endl;
		cout << *iter++ << " " ;
		cout << *iter << endl;
	}
	else
		cout << "链表中没有奇偶同性的相邻元素" << endl;

	system("pause");
	return 0;
}