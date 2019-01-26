
// stream iterator这是一个用来读写steram的迭代器.他们提供了必要的抽象
// 性,使得来自键盘的输入像是个群集(collection),能够从中读取内容.同样
// 也可以把一个算法的输出结果重新导向到某个文件或屏幕上

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
	vector<string> coll;
	vector<string>::iterator iter;
	cout << "input text(end of Ctrl + Z): " << endl;

	// read all words from the standard input
	// - source: all strings until end-of-file(or error)
	// - destination: coll(inserting)
	// istream_iterator<string>(cin)产生一个可从标准输入流(standard input stream)
	// 读取数据的stream iterator,这些元素通过一般的operator>>被读进来
	// 被当处理下一个元素时将会变为: cin >> string;
	// istream_iterator<string>()调用默认构造函数,产生一个代表流结束符号
	// (end of stream)的迭代器,代表的意思是:不能在从中读取任何东西
	// 针对string执行input操作符通常读取以空白分隔的文字,因此下面的行为将
	// 是逐词读取(word by word)
	copy(istream_iterator<string>(cin),		// start of source
			istream_iterator<string>(),		// end of source
			back_inserter(coll));			// destination

	// print
	cout << "Before sort: " << endl;
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout << *iter << endl;
	cout << endl;

	// sort elements
	sort(coll.begin(), coll.end());

	// print all elements without duplicates
	// - source: coll
	// - destination: standard output (with newline between elements)
	cout << "After sort: " << endl;

	// ostream_iterator<string>(cout, "\n")产生一个output stream iterator
	// 通过operator<<向cout中写入strings,第二个参数(可有可无)被用来指定
	// 元素之间的分隔符
	unique_copy(coll.begin(), coll.end(),				// source
				ostream_iterator<string>(cout, "\n"));	// destination
	cout << endl;

	system("pause");
	return 0;
}