
/***********************************************************
 * @name: bind2nd_1.cpp
 * @brief: bind2nd
 * @author: Jisheng Liang
 * @date: 2018/6/30 15:18:59
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
	const int N = sizeof(intArr) / sizeof(int);
	vector<int> a(intArr, intArr + N);
	vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 40));
	if (p == a.end())
		cout << "no element greater than 40" << endl;
	else
		cout << "first element greater than 40 is: " << *p << endl;

	getchar();
	return 0;
}
