
/***********************************************************
 * @name: iterator loss efficacy 1.cpp
 * @brief: 迭代器失效
 * @author: 梁基圣
 * @date: 2018/7/24 9:08:57
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void PrintVector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
}

void TestIterator()
{
	// 迭代器失效
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(4);
	v.push_back(4);
	v.push_back(6);
	PrintVector(v);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		// erase 返回删除迭代器的下一个有效迭代器
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	PrintVector(v);
}


int main()
{
	TestIterator();

	getchar();
	return 0;
}
