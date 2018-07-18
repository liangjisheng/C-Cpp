
/***********************************************************
 * @name: ptr_fun_1.cpp
 * @brief: ptr_fun_1
 * @author: Jisheng Liang
 * @date: 2018/6/30 15:24:07
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool g(int x, int y) { return x > y; }

int main()
{
	int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
	const int N = sizeof(intArr) / sizeof(int);
	vector<int> a(intArr, intArr + N);

	vector<int>::iterator p;
	p = find_if(a.begin(), a.end(), bind2nd(ptr_fun(g), 40));
	if (p == a.end())
		cout << "no element greater than 40" << endl;
	else
		cout << "first element greater than 40 is: " << *p << endl;

	p = find_if(a.begin(), a.end(), not1(bind2nd(greater<int>(), 15)));
	if (p == a.end())
		cout << "no element is not greater than 15" << endl;
	else
		cout << "first element that is not greater than 15 is: " << *p << endl;

	p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()), 15));
	if (p == a.end())
		cout << "no element is not greater than 15" << endl;
	else
		cout << "first element that is not greater than 15 is: " << *p << endl;

	getchar();
	return 0;
}
