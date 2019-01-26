
#include <iostream>
#include <fstream>

using namespace std;

void redirect(ostream&);

int main()
{
	cout << "the first row" << endl;
	redirect(cout);
	cout << "the last row" << endl;

	system("pause");
	return 0;
}

void redirect(ostream& strm)
{
	ofstream file("redirect.txt");

	// save output buffer of the stream
	streambuf* strm_buffer = strm.rdbuf();

	// redirect output into the file
	// 将strm流重定向至文件流
	strm.rdbuf(file.rdbuf());

	file << "one row for the file" << endl;
	strm << "one row for the stream" << endl;

	// restore old output buffer
	strm.rdbuf(strm_buffer);
}	// close file and its buffer automatically
