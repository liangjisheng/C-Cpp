
// str()是string stream classes最主要的一个函数，用来管理字符串流缓冲区
// str()将缓冲区内容当做一个string返回
// str(string)将string设为缓冲区内容

#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

int main()
{
	ostringstream os;

	// decimal and hexadecimal value
	os << "dec: " << 15 << hex << " hex: " << 15 << endl;
	cout << os.str() << endl;

	// append floating value and bitset
	bitset<15> b(5789);
	os << "float: " << 4.67 << " bitset: " << b << endl;

	// overwrite with octal value
	os.seekp(0);
	os << "oct: " << oct << 15;
	cout << os.str() << endl;

	system("pause");
	return 0;
}