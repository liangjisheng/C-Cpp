
/***********************************************************
 * @name: iterator loss efficacy 3.cpp
 * @brief: 迭代器失效
 * @author: 梁基圣
 * @date: 2018/7/24 9:37:37
 * @version: 1.0
 **********************************************************/

// 对于关联容器(如map, set,multimap,multiset)，删除当前的
// iterator，仅仅会使当前的iterator失效，只要在erase时，递增
// 当前iterator即可.这是因为map之类的容器,使用了红黑树来实现
// 插入、删除一个结点不会对其他结点造成影响。erase迭代器只是
// 被删元素的迭代器失效,但是返回值为void,所以要采用
// erase(iter++)的方式删除迭代器.
// map是关联容器，以红黑树或者平衡二叉树组织数据，虽然删除了
// 一个元素，整棵树也会调整，以符合红黑树或者二叉树的规范，但
// 是单个节点在内存中的地址没有变化，变化的是各节点之间的指向关系

#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void mapTest_error()
{
	map<int, string> dataMap;

	for (int i = 0; i < 100; ++i)
	{
		string strValue = "Hello, World ";
		stringstream ss;
		ss << i;
		string strCount;
		ss >> strCount;
		strValue += strCount;
		dataMap.insert(make_pair(i, strValue));
	}

	cout << "Map元素内容为: " << endl;
	map<int, string>::iterator iter = dataMap.begin();
	for (; iter != dataMap.end(); iter++)
	{
		int nKey = iter->first;
		string strValue = iter->second;
		cout << strValue << endl;
	}

	cout << "内容开始删除: " << endl;
	// 擦除操作引发迭代器失效
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++)
	{
		int nKey = iter->first;
		string strValue = iter->second;

		// dataMap.erase(iter)之后, iter就已经失效了，所以iter无法自增，
		// 即iter++就会出bug.解决方案，就是在iter失效之前，先自增
		if (nKey % 2 == 0)
			dataMap.erase(iter);
	}
}

void mapTest_correct()
{
	map<int, string> dataMap;

	for (int i = 0; i < 100; ++i)
	{
		string strValue = "Hello, World ";
		stringstream ss;
		ss << i;
		string strCount;
		ss >> strCount;
		strValue += strCount;
		dataMap.insert(make_pair(i, strValue));
	}

	cout << "Map元素内容为: " << endl;
	map<int, string>::iterator iter = dataMap.begin();
	for (; iter != dataMap.end(); iter++)
	{
		int nKey = iter->first;
		string strValue = iter->second;
		cout << strValue << endl;
	}

	cout << "内容开始删除: " << endl;
	for (iter = dataMap.begin(); iter != dataMap.end(); )
	{
		int nKey = iter->first;
		string strValue = iter->second;


		if (nKey % 2 == 0)
		{
			// dataMap.erase(iter++);这句话分三步走，先把iter传值到erase里面，
			// 然后iter自增，然后执行erase,所以iter在失效前已经自增了。
			dataMap.erase(iter++);
			map<int, string>::iterator a = iter;
		}
		else
			iter++;
	}
}


int main()
{
	// mapTest_error();
	mapTest_correct();

	getchar();
	return 0;
}

// 总结:迭代器失效分三种情况考虑,也是分三种数据结构考虑,
// 分别为数组型,链表型,树型数据结构.
// 数组型数据结构:该数据结构的元素是分配在连续的内存中,
// insert和erase操作,都会使得删除点和插入点之后的元素挪
// 位置,所以,插入点和删除掉之后的迭代器全部失效,也就是
// 说insert(*iter)(或erase(*iter)),然后在iter++，是没有
// 意义的.解决方法:erase(*iter)的返回值是下一个有效迭代
// 器的值. iter = cont.erase(iter);
// 链表型数据结构:对于list型的数据结构,使用了不连续分配
// 的内存,删除运算使指向删除位置的迭代器失效,但是不会失
// 效其他迭代器.解决办法两种,erase(*iter)会返回下一个有
// 效迭代器的值,或者erase(iter++).
// 树形数据结构:使用红黑树来存储数据,插入不会使得任何迭
// 代器失效;删除运算使指向删除位置的迭代器失效,但是不会
// 失效其他迭代器.erase迭代器只是被删元素的迭代器失效,
// 但是返回值为void,所以要采用erase(iter++)的方式删除迭代器
// 注意:经过erase(iter)之后的迭代器完全失效,该迭代器iter
// 不能参与任何运算,包括iter++, *iter.
