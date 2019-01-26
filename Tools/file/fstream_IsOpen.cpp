
#include <iostream>
#include <fstream>
#include <string.h>

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

// 缓存和同步(Buffers and Synchronization)
// 当我们对文件流进行操作的时候，它们与一个streambuf 类型的缓存(buffer)
// 联系在一起。这个缓存（buffer）实际是一块内存空间，作为流(stream)
// 和物理文件的媒介。例如，对于一个输出流， 每次成员函数put (写一个单个字符)
// 被调用，这个字符不是直接被写入该输出流所对应的物理文件中的，而是首先被
// 插入到该流的缓存（buffer）中。

// 当缓存被排放出来(flush)时，它里面的所有数据或者被写入物理媒质中
// (如果是一个输出流的话),或者简单的被抹掉(如果是一个输入流的话)
// 这个过程称为同步(synchronization)，它会在以下任一情况下发生：
// 当文件被关闭时: 在文件被关闭之前，所有还没有被完全写出或读取的缓存都将被同步
// 当缓存buffer 满时:缓存Buffers 有一定的空间限制。当缓存满时，它会被自动同步
// 控制符明确指明:当遇到流中某些特定的控制符时，同步会发生
// 这些控制符包括：flush 和endl。
// 明确调用函数sync(): 调用成员函数sync() (无参数)可以引发立即同步
// 这个函数返回一个int 值，等于-1 表示流没有联系的缓存或操作失败。

// fstream中有一个open()
// void open(const char* filename,int mode,int access);
// 第三个参数表示打开文件的属性取值
// 0:普通文件，打开访问
// 1:只读文件
// 2:隐含文件
// 3:系统文件


void test_ofstream()
{
	ofstream out("test.txt");		// 默认打开方式	ios::out | ios::trunc
	if(!out.is_open())
	{
		cerr << "open file failed" << endl;
		return ;
	}
	else
	{
		out << "This is a line\n";
		out << "This is another line\n";
		out.close();
	}
}

// 另外一些检查文件状态的标志，bad()读写文件出错，fail()除了与bad()同样的情况下
// 返回true，格式错误时也返回true，例如当想读入一个整数，而获得了一个字母的时候
// eof()到达文件尾，good()调用以上三个函数返回true的话，good()返回false
void test_ifstream()
{
	char buffer[256] = {0};
	ifstream in("test.txt");
	if(!in.is_open())
	{
		cerr << "open file failed" << endl;
		return ;
	}
	else
	{
		int nReadCount = 0;
		do
		{
			in.getline(buffer, 255);		// 默认遇到换行符结束
			nReadCount = in.gcount();
			int nCom = strcmp(buffer, "");
			if(0 != nCom)
			{
				cout << buffer << endl;
				for(int i = 0; i < nReadCount; i++)
					cout << (int)buffer[i] << " ";
				cout << endl;
				memset(buffer, 0, nReadCount);
			}
			else
			{
				/*for(int i = 0; i < 15; i++)
					cout << (int)buffer[i] << " ";
				cout << endl;*/
				cout << "end of file" << endl;
			}
			
		} while (!in.eof() && nReadCount > 0);
	}
}

// 获得一个二进制文件的大小
void test_ifstream_1()
{
	long l = 0, m = 0;
	//  | ios::binary,用不用二进制的方式打开文件都可以得到文件的大小
	ifstream in("test.txt", ios::in);
	l = in.tellg();
	in.seekg(0, ios::end);
	m = in.tellg();
	in.close();
	cout << "sizeof test.txt is " << m - l << " bytes" << endl;
}

void test_ifstream_2()
{
	char *buffer = NULL;
	long size = 0;
	// ate表示打开文件的时候将get指针移到最后
	ifstream in("test.txt", ios::in | ios::binary | ios::ate);
	size = in.tellg();
	in.seekg(0, ios::beg);
	buffer = new char[size + 1];
	memset(buffer, 0, size + 1);
	in.read(buffer, size);
	int nReadCount = in.gcount();
	in.close();

	buffer[size] = 0;
	cout << buffer << endl;
	cout << "read count = " << nReadCount << endl;
	cout << "strlen(buffer) = " << strlen(buffer) << endl;
	for(int i = 0; i < nReadCount; i++)
		cout << (int)buffer[i] << " ";
	cout << endl;
}


int main()
{
	// test_ofstream();
	// test_ifstream();
	// test_ifstream_1();
	test_ifstream_2();

	system("pause");
	return 0;
}

