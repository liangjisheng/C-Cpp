
// 从标准输入读取字符串，进行排序，然后打印所有元素(去掉重复字符串)
// Ctrl+Z输入结束

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	cout << " input some words: " << endl;

	/* create a string vector
	 * initialized by all words from stardard input
	*/
	vector<string> coll1((istream_iterator<string>(cin)),
			(istream_iterator<string>()));

	// print all elements ignoring subsequent duplicates
	cout << endl;
	unique_copy(coll1.begin(), coll1.end(), 
		ostream_iterator<string>(cout, "\n"));

	// sort element
	sort(coll1.begin(), coll1.end());

	// print all elements ignoring subsequent duplicates
	cout << endl;
	unique_copy(coll1.begin(), coll1.end(), 
		ostream_iterator<string>(cout, "\n"));

	system("pause");
	return 0;
}