
// read text file
#include <iostream>
#include <fstream>

using std::cout;
using std::ifstream;
using std::ios;

int main()
{
	char* buffer = NULL;
	long size = 0;
	// ios::ate表示将get指针放到文件尾
	ifstream in("out.txt", ios::in | ios::ate);
	if(in.is_open())
	{
		size = in.tellg();
		// 此时get指针在文件尾，必须把文件指针放到文件头，才能准确读取
		in.seekg(0, ios::beg);
		buffer = new char[size];
		memset(buffer, 0, size);
		in.read(buffer, size);
		buffer[size - 1] = '\0';
		in.close();
		cout << buffer << "\n";
		delete []buffer;
	}

	system("pause");
	return 0;
}


// 缓存和同步(Buffers and Synchronization)
// 当我们对文件流进行操作的时候，它们与一个streambuf 类型的缓存(buffer)联系在一起。
// 这个缓存（buffer）实际是一块内存空间，作为流(stream)和物理文件的媒介。
// 例如，对于一个输出流， 每次成员函数put (写一个单个字符)被调用，
// 这个字符不是直接被写入该输出流所对应的物理文件中的，而是首先被插入到该流的缓存（buffer）中。
// 当缓存被排放出来(flush)时，它里面的所有数据或者被写入物理媒质中（如果是一个输出流的话），
// 或者简单的被抹掉(如果是一个输入流的话)。这个过程称为同步(synchronization)，
// 它会在以下任一情况下发生：
// 当文件被关闭时: 在文件被关闭之前，所有还没有被完全写出或读取的缓存都将被同步。
// 当缓存buffer 满时:缓存Buffers 有一定的空间限制。当缓存满时，它会被自动同步。
// 控制符明确指明:当遇到流中某些特定的控制符时，同步会发生。这些控制符包括：flush 和endl。
// 明确调用函数sync(): 调用成员函数sync() (无参数)可以引发立即同步。这个函数返回一个int 值，
// 等于-1 表示流没有联系的缓存或操作失败。

