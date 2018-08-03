
/***********************************************************
 * @name: map_erase.cpp
 * @brief: erase
 * @author: 梁基圣
 * @date: 2018/7/24 14:14:19
 * @version: 1.0
 **********************************************************/

// 该成员方法的定义如下:
// iterator erase(iterator it);//通过一个条目对象删除
// iterator erase(iterator first,iterator last)//删除一个范围
// size_type erase(const Key&key);//通过关键字删除
// clear()就相当于erase(map.begin(), map.end());

#include <iostream>
#include <map>
#include <string>

using namespace std;

void map_erase()
{
	map<int, string> map1;
	map1.insert(pair<int, string>(1, "one"));
	map1.insert(pair<int, string>(2, "two"));
	map1.insert(pair<int, string>(3, "three"));

	map<int, string>::iterator iter = map1.find(1);
	map1.erase(iter);

	iter = map1.begin();
	for (; iter != map1.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
}

int main()
{
	map_erase();

	getchar();
	return 0;
}
