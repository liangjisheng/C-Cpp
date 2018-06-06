
#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

int main()
{
	char str[10] = "ABC我们";		// 占7个字节
	cout << sizeof(str) << endl;
	char *p = str;
	for(int i = 0; i < 10; i++)
		cout << (int)*p++ << " ";
	cout << endl;
	for(int i = 0; i < 10; i++)
		cout << (int)str[i] << " ";
	cout << endl;

	wchar_t wstr[20]  = L"ABC我们";
	cout << sizeof(wstr) << endl;
	p = (char*)wstr;
	for(int i = 0; i < 20; i++)
		cout << (int)*p++ << " ";
	cout << endl;
	for(int i = 0; i < 20; i++)
		cout << (int)wstr[i] << " ";
	cout << endl;

	ofstream ofs("file1.txt");
	ofs << str;
	ofs.close();

	wofstream wofs("file2.txt");
	// 虽然设置了文件输出流对象的locale,但那只是保证了wchar_t
	// 类型的字符串(中的中文字符)能够被输出到文件中,但是任然
	// 按照多字节字符串的编码输出,所以file1.txt与file2.txt文件
	// 的内容和大小都是一样的,都是7个字节
	wofs.imbue(locale("CHS"));
	wofs << wstr;
	wofs.close();

	ofs.open("file3.txt");
	short flag = 0xFEFF;		// Unicode编码标志
	// 在文件的开头以二进制写一个Unicode编码标志
	ofs.write((char*)&flag, sizeof(short));
	// 以二进制方式将wchar_t类型的字符串写入文件
	ofs.write((char*)wstr, wcslen(wstr) * 2);
	ofs.close();

	system("pause");
	return 0;
}