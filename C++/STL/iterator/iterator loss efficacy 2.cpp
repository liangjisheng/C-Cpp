
/***********************************************************
 * @name: iterator loss efficacy 2.cpp
 * @brief: 迭代器失效
 * @author: 梁基圣
 * @date: 2018/7/24 9:25:18
 * @version: 1.0
 **********************************************************/

// 因为vetor,deque使用了连续分配的内存，删除一个元素导致后面
// 所有的元素会向前移动一个位置。所以不能使用erase(iter++)的
// 方式，还好erase方法可以返回下一个有效的iterator.
// 对于序列式容器，比如vector，删除当前的iterator会使后面所有
// 元素的iterator都失效

#include <iostream>
#include <vector>

using namespace std;

void vectorTest_error()
{
	vector<int> coll;
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	vector<int>::iterator iter = coll.begin();
	for (; iter != coll.end(); iter++)
	{
		// 第一次erase后，iter会失效，接下来再执行++操作是会产生未定义行为
		if (*iter > 3)
			coll.erase(iter);
	}

	for (iter = coll.begin(); iter != coll.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
}

void vectorTest_correct()
{
	vector<int> coll;
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	vector<int>::iterator iter = coll.begin();
	for (; iter != coll.end(); )
	{
		// 第一次erase后，iter会失效，接下来再执行++操作是会产生未定义行为
		if (*iter > 3)
			iter = coll.erase(iter);
		else
			iter++;
	}

	for (iter = coll.begin(); iter != coll.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
}


int main()
{
	// vectorTest_error();
	vectorTest_correct();

	getchar();
	return 0;
}
