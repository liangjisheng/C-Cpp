
/***********************************************************
 * @name: map_find.cpp
 * @brief: map find
 * @author: 梁基圣
 * @date: 2018/7/24 13:55:01
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

void map_find()
{
	map<int, string> map1;
	map1.insert(pair<int, string>(1, "one"));
	map1.insert(pair<int, string>(2, "two"));
	map1.insert(pair<int, string>(3, "three"));

	map<int, string>::iterator iter = map1.find(1);
	if (iter != map1.end())
		cout << "Find, the value is " << iter->second << endl;
	else
		cout << "Do not Find" << endl;
}

void map_find_1()
{
	// lower_bound函数用法，这个函数用来返回要查找关键字的下界(是一个迭代器)
	// upper_bound函数用法，这个函数用来返回要查找关键字的上界(是一个迭代器)
	// 例如: map中已经插入了1，2，3，4的话，如果lower_bound(2)的话，返回的2，
	// 而upper-bound（2）的话，返回的就是3.
	// Equal_range函数返回一个pair，pair里面第一个变量是Lower_bound返回的迭代器，
	// pair里面第二个迭代器是Upper_bound返回的迭代器，如果这两个迭代器相等的话，
	// 则说明map中不出现这个关键字，

	map<int, string> map1;
	map1[1] = "one";
	map1[3] = "three";
	map1[5] = "five";

	// 返回的是下界1的迭代器
	map<int, string>::iterator iter = map1.lower_bound(1);
	cout << iter->second << endl;
	// 返回的是下界3的迭代器
	iter = map1.lower_bound(2);
	cout << iter->second << endl;
	// 返回的是下界3的迭代器
	iter = map1.lower_bound(3);
	cout << iter->second << endl;
	cout << endl;

	// 返回的是上界3的迭代器
	iter = map1.upper_bound(2);
	cout << iter->second << endl;
	// 返回的是上界5的迭代器
	iter = map1.upper_bound(3);
	cout << iter->second << endl;

	pair<map<int, string>::iterator, map<int, string>::iterator> mappair;
	mappair = map1.equal_range(2);
	if (mappair.first == mappair.second)
		cout << "Do not Find" << endl;
	else
		cout << "Find" << endl;

	mappair = map1.equal_range(3);
	if (mappair.first == mappair.second)
		cout << "Do not Find" << endl;
	else
		cout << "Find" << endl;
}


int main()
{
	// map_find();
	map_find_1();

	getchar();
	return 0;
}
