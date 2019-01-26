
// 从标准输入读取字符串，进行排序，然后打印所有元素(去掉重复字符串)
// Ctrl+Z输入结束

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	cout << "input some word: " << endl;

	/* create a string set
	 * initialized by all words from standard input
	*/
	set<string> coll((istream_iterator<string>(cin)),
		(istream_iterator<string>()));

	// print all elements
	copy(coll.begin(), coll.end(),
			ostream_iterator<string>(cout, "\n"));

	system("pause");
	return 0;
}