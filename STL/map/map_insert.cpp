
/***********************************************************
 * @name: map_insert.cpp
 * @brief: map
 * @author: 梁基圣
 * @date: 2018/7/24 10:56:34
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

// 前向常量迭代器遍历map
void printMap(const map<int, string>& dataMap)
{
	map<int, string>::const_iterator iter = dataMap.begin();
	for (; iter != dataMap.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
}

// 反向常量迭代器遍历map
void printMapReverse(const map<int, string>& dataMap)
{
	map<int, string>::const_reverse_iterator iter = dataMap.rbegin();
	for (; iter != dataMap.rend(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
}

void insert_test()
{
	map<int, string> mapstu;
	mapstu.insert(pair<int, string>(1, "one"));
	mapstu.insert(pair<int, string>(2, "two"));
	mapstu.insert(pair<int, string>(3, "three"));

	printMap(mapstu);
}

void insert_test_1()
{
	map<int, string> mapstu;
	mapstu.insert(map<int, string>::value_type(1, "one"));
	mapstu.insert(map<int, string>::value_type(2, "two"));
	mapstu.insert(map<int, string>::value_type(3, "three"));

	printMap(mapstu);
}

void insert_test_2()
{
	map<int, string> mapstu;
	mapstu[0] = "one";
	mapstu[1] = "two";
	mapstu[2] = "three";

	printMap(mapstu);
}

// pair<map<int, string>::iterator, bool> Insert_Pair;
// Insert_Pair = mapStudent.insert(map<int, string>::value_type(1, "student_one"));
// 我们通过pair的第二个变量来知道是否插入成功，它的第一个变量返回
// 的是一个map的迭代器，如果插入成功的话Insert_Pair.second应该是true的，否则为false
void insert_test_3()
{
	map<int, string> mapstu;
	pair<map<int, string>::iterator, bool> insert_pair;
	int num = 1;
	string str = "one";
	insert_pair = mapstu.insert(pair<int, string>(num, str));
	if (insert_pair.second)
		cout << "Insert Successfully " << num << endl;
	else
		cout << "Insert Failure " << num << endl;

	str = "two";
	insert_pair = mapstu.insert(pair<int, string>(num, str));
	if (insert_pair.second)
		cout << "Insert Successfully " << num << endl;
	else
		cout << "Insert Failure " << num << endl;

	printMap(mapstu);
}

void insert_test_4()
{
	map<int, string> mapstu;
	mapstu[1] = "one";
	mapstu[2] = "two";
	mapstu[1] = "three";

	printMap(mapstu);
	// printMapReverse(mapstu);
}


int main()
{
	// insert_test();
	// insert_test_1();
	// insert_test_2();

	// 以上三种用法,虽然都可以实现数据的插入,但是它们是有区别的,
	// 当然了第一种和第二种在效果上是完成一样的,用insert函数插入
	// 数据,在数据的插入上涉及到集合的唯一性这个概念,即当map中有
	// 这个关键字时,insert操作是插入数据不了的,但是用数组方式就
	// 不同了,它可以覆盖以前该关键字对应的值
	// insert_test_3();
	insert_test_4();

	getchar();
	return 0;
}
