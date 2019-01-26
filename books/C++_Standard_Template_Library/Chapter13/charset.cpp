
// 打开文件是否成功会反映在文件流的状态中
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>		// for exit()

using namespace std;

void writeCharsetToFile(const string& filename);
void outputFile(const string& filename);

int main()
{
	writeCharsetToFile("charset.out");
	outputFile("charset.out");

	system("pause");
	return 0;
}

void writeCharsetToFile(const string& filename)
{
	ofstream file(filename.c_str());

	// file opened?
	if (!file)
	{
		// NO, abort program
		cerr << "can't open output file \"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	// write character set
	for (int i = 32; i < 256; ++i)
		file << "value: " << setw(3) << i << " "
			<< "char: " << static_cast<char>(i) << endl;
}	// close file automatically

void outputFile(const string& filename)
{
	ifstream file(filename.c_str());

	// file opened?
	if (!file)
	{
		// NO, abort program
		cerr << "can't open input file \"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	// copy file contents to cout
	char c;
	while (file.get(c))
		cout.put(c);

	// 还可以使用单一语句输出所有内容，将file stream的缓冲区指针当做参数，传给operator<<E
	// cout << file.rdbuf();
}	// close file automatically
