
// obtain file size
#include <iostream>
#include <fstream>

using std::cout;
using std::ifstream;
using std::ios;

// 所有输入/输出流对象(i/o streams objects)都有至少一个流指针：
// ifstream， 类似istream, 有一个被称为get pointer的指针，指向下一个将被读取的元素。
// ofstream, 类似 ostream, 有一个指针 put pointer ，指向写入下一个元素的位置。
// fstream, 类似 iostream, 同时继承了get 和 put

int main()
{
	long l = 0, m = 0;
	ifstream in("out.txt", ios::in);
	if(in.is_open())
	{
		l = in.tellg();
		in.seekg(0, ios::end);
		m = in.tellg();
		in.close();

		cout << "file size is " << m - 1 << " bytes\n";
	}
	else
		cout << "Error open file.\n";

	system("pause");
	return 0;
}
