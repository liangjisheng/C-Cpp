
// 通过文件指针的定位，修改某个已经存在的文件中的部分内容

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char arr[] = "ABCDABCD";
	ofstream out("1.bin", ios_base::out | ios_base::binary);
	int nLen = strlen(arr);
	out.write(arr, nLen);
	out.close();

	char c = '\0';
	ios::streampos position;
	fstream fout("1.bin", ios::in | ios::binary);
	fout.seekp(0L, ios::end);
	position = fout.tellp();
	fout.seekp(0L, ios::beg);
	cout << position << endl;

	// 不能使用fout.eof()来判读是否达到文件的末尾，因为程序必须在文件
	// 的末尾地方执行一次读取操作，才能确定是否达到文件末尾，而此时
	// 有可能读取的字符本身就是'A',这样导致新的写入动作，对于纯输入文件
	// 使用eof()函数，对于同时可读写的文件，应该采用其他方式判断文件
	// 是否结束
	while(fout.tellp() != position)
	{
		fout.read(&c, 1);
		cout << fout.tellp() << endl;
		if(c == 'A')
		{			
			c = '0';
			fout.write(&c, 1);
			fout.seekp(-1L, ios::cur);
		}
	}

	fout.close();

	system("pause");
	return 0;
}