
/***********************************************************
 * @name: list_1.cpp
 * @brief: list
 * @author: Jisheng Liang
 * @date: 2018/6/30 12:25:42
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	string names2[] = { "Bob", "David", "Levin", "Mike" };
	list<string> s1(names1, names1 + sizeof(names1) / sizeof(names1[0]));
	list<string> s2(names2, names2 + sizeof(names1) / sizeof(names1[0]));

	// s1.splice(p, s2, q1, q2):将s2中[q1, q2)移动到s1中p所指向元素之前
	s2.splice(s2.end(), s1, s1.begin());
	list<string>::iterator iter1 = s1.begin();
	advance(iter1, 2);
	list<string>::iterator iter2 = s2.begin();
	++iter2;
	list<string>::iterator iter3 = iter2;
	advance(iter3, 2);
	s1.splice(iter1, s2, iter2, iter3);

	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	getchar();
	return 0;
}
