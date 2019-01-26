
// read a text file
#include <iostream>
#include <fstream>
#include <stdlib.h>			// for exit()

using std::ifstream;
using std::cout;
using std::endl;

int main()
{
	char buffer[256] = {0};
	ifstream in("out.txt");
	if(!in.is_open())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}

	// 如果没有达到文件最后
	while(!in.eof())
	{
		in.getline(buffer, sizeof(buffer));
		cout << buffer << endl;
	}

	// 还有一些验证流的状态的成员函数（所有都返回bool型返回值）：
	// bad()
	// 如果在读写过程中出错，返回 true 。例如：当我们要对一个不是打开为写状态的文件进行写入时，
	// 或者我们要写入的设备没有剩余空间的时候。
	// fail()
	// 除了与bad() 同样的情况下会返回 true 以外，加上格式错误时也返回true ，
	// 例如当想要读入一个整数，而获得了一个字母的时候。
	// eof()
	// 如果读文件到达文件末尾，返回true。
	// good()
	// 这是最通用的：如果调用以上任何一个函数返回true 的话，此函数返回 false 。
	// 重置以上状态标志，可以使用流的成员函数clear()

	system("pause");
	return 0;
}