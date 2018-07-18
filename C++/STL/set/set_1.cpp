
/***********************************************************
 * @name: set_1.cpp
 * @brief: set_1
 * @author: Jisheng Liang
 * @date: 2018/6/30 14:55:52
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	cout << "input some number(0 for end): " << endl;
	set<double> s;
	while (true)
	{
		double v;
		cin >> v;
		if (0 == v)
			break;

		// 将v插入，得到返回值
		pair<set<double>::iterator, bool> r = s.insert(v);
		if (!r.second)
			cout << v << " is duplicated" << endl;
	}

	// set是有序的
	set<double>::iterator iter1 = s.begin();
	set<double>::iterator iter2 = s.end();
	double medium = (*iter1 + *(--iter2)) / 2;		// 得到最大和最小元素的中值

	cout << "<= medium: " << endl;
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout << endl;
	cout << ">= medium: " << endl;
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout << endl;

	getchar();
	return 0;
}
