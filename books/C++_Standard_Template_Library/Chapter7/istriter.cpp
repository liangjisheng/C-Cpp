
// 通过istream迭代器，算法可以直接从steam中读取数据，istream迭代器比ostream迭代器要复杂一些
// 通常情况下,读比写要复杂。读取操作可能失败(可能读取到文件尾，或读取错误)，另外算法也需要
// 知道区间是否已经到达终点。为了解决这些问题，可以使用一个end-of-stream迭代器，有istream
// 迭代器的默认构造函数生成，只要有任何一次读取失败，所有istream迭代器都会变成end-of-stream
// 迭代器，在进行一次读取后，应该将istream迭代器和end-of-stream迭代器进行比较，看看这个迭代器
// 是否合法

// 满足下面两个条件，便认为两个istream迭代器相等
// 两者都是end-of-istream迭代器(不能进行读取操作)或
// 两者都可以进行读取操作，并指向相同的stream

#include <iostream>
#include <iterator>

using namespace std;

// 输入： 1 2 3 f 4 

int main()
{
	// create istream iterator that reads integers from cin
	istream_iterator<int> intReader(cin);

	// create end-of-stream iterator
	istream_iterator<int> intReaderEOF;

	// while able to read tokens with istream iterator
	// write them twice
	while (intReader != intReaderEOF)
	{
		cout << "once: " << *intReader << endl;
		cout << "once again: " << *intReader << endl;
		// 读取下一个元素
		++intReader;
	}

	system("pause");
	return 0;
}