
/***********************************************************
 * @name: streambuf.cpp
 * @brief: streambuf
 * @author: Jisheng Liang
 * @date: 2018/6/29 19:47:09
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int main()
{
	ifstream in("test.c");
	ofstream out("testcopy.c", std::ios_base::out);
	// 每个输入输出流都有一个成员函数rdbuf(),返回指向对象streambuf的指针
	cout << in.rdbuf() << endl;
	in.seekg(0);
	out << in.rdbuf() << endl;
	in.close();
	out.close();

	system("pause");
	return 0;
}
