
// 文本文件也可以用二进制文件打开，此程序采用二进制文件读写的方式
// 实现文件的的快速拷贝,此程序不论是对文本文件还是二进制文件都能
// 正常工作

#include <iostream>
#include <fstream>

using std::ios_base;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


int main(int argc, char** argv)
{
	const static int BUF_SIZE = 4096;
	if(argc != 3)
	{
		cout << "Usage: copy source file target file" << endl;
		return 1;
	}

	ifstream in(argv[1], ios_base::in | ios_base::binary);
	ofstream out(argv[2], ios_base::out | ios_base::binary);
	// 利用重载操作符!来判断打开或创建文件的操作是否成功
	if(!in || !out)
	{
		cout << "opening or creating file failed" << endl;
		return 1;
	}

	char buf[BUF_SIZE] = {0};
	do 
	{
		in.read(buf, BUF_SIZE);
		out.write(buf, in.gcount());
	} while (in.gcount() > 0);

	in.close();
	out.close();
		
	system("pause");
	return 0;
}