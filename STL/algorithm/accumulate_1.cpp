
/***********************************************************
 * @name: accumulate_1.cpp
 * @brief: accumulate
 * @author: Jisheng Liang
 * @date: 2018/6/30 15:13:15
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	const int N = sizeof(a) / sizeof(a[0]);
	// 连乘
	cout << "The result of multiply all elements in A is " <<
		accumulate(a, a + N, 1, multiplies<int>()) << endl;

	getchar();
	return 0;
}
