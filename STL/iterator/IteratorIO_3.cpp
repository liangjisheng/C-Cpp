
/***********************************************************
 * @name: IOIterator_1.cpp
 * @brief: InputIterator
 * @author: Jisheng Liang
 * @date: 2018/6/30 12:04:48
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

// 将来自输入迭代器first的n个T类型的数值排序，将结果通过输出迭代器result输出
template<class T, class InputIterator, class OutputIterator>
void mysort(InputIterator first, InputIterator last, OutputIterator result)
{
	vector<T> s;
	for (; first != last; ++first)
		s.push_back(*first);
	sort(s.begin(), s.end());	// sort的参数必须是随机访问迭代器
	copy(s.begin(), s.end(), result);
}

int main()
{
	double a[5] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
	mysort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
	cout << endl;

	//从标准输入读入若干个整数，将排序后的结果输出
	cout << "input some number to sort(Ctrl+d for end): " << endl;
	mysort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	cout << endl;

	getchar();
	return 0;
}
