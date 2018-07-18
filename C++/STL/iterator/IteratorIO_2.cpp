
/***********************************************************
 * @name: IOIterator.cpp
 * @brief: istream_iterator and ostream_iterator
 * @author: Jisheng Liang
 * @date: 2018/6/30 11:55:41
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

double square(double x) { return x * x; }

int main()
{
	cout << "input double type number(Ctrl+D for quit): " << endl;
	// 从标准输入读入若干个实数，分别将它们的平方输出
	transform(istream_iterator<double>(cin),
		istream_iterator<double>(),
		ostream_iterator<double>(cout, "\n"),
		square);

	getchar();
	return 0;
}
