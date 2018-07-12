
// cout,cerr重定向,C++标准中cerr不能被重定向，但多数编译器都支持cerr重定向

#include <iostream>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::streambuf;


void test_1()
{
	ofstream ofs("test.txt");
	// rdbuf()函数可以对cout和cerr重定向
	streambuf *pOutBuf = cout.rdbuf(ofs.rdbuf());
	streambuf *pErrBuf = cerr.rdbuf(ofs.rdbuf());
	cout << "no error" << endl;		// 输出到文件test.txt中
	cout << "error" << endl;		// 输出到文件test.txt中

	cout.rdbuf(pOutBuf);			// 恢复原来的输出设备
	cerr.rdbuf(pErrBuf);
}


int main()
{
	test_1();

	system("pause");
	return 0;
}

