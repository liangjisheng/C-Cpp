
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// open file "example.dat" for reading and writing
	filebuf buffer;				// 文件流缓冲区，filebuf是class basic_filebuf<>对于字符类型char的特化实例
	ostream output(&buffer);	// 将文件流缓冲区安装在一个输出流上构成一个输出文件流
	istream input(&buffer);		// 将文件流缓冲区安装在一个输入流上构成一个输入文件流
	buffer.open("example.dat", ios::in | ios::out | ios::trunc);

	for (int i = 1; i <= 4; ++i)
	{
		// write one line
		output << i << ". line" << endl;

		// print all file contents
		input.seekg(0);	// seek to the beginning
		cout << input.rdbuf();	// 和下面三行的效果一样
		//char c;
		//while (input.get(c))
		//	cout.put(c);
		cout << endl;
		input.clear();	// clear eofbit and failbit
	}

	system("pause");
	return 0;
}