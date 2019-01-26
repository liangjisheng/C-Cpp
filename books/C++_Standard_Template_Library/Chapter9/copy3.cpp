
// 使用copy()作为标准输入和标准输出之间的数据过滤器
// 程序读取strings，并以一行一个的方式打印他们

#include "..\..\algostuff.hpp"
using namespace std;

int main()
{
	copy(istream_iterator<string>(cin),			// begin of source
		istream_iterator<string>(),				// end of source
		ostream_iterator<string>(cout, "\n"));	// destination

	system("pause");
	return 0;
}