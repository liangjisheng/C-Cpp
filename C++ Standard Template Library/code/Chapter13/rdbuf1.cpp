
#include <iostream>
#include <fstream>

using namespace std;

// 通过rdbuf()函数，可以使不同的streams共享同一个缓冲区，从而实现streams的紧耦合

int main()
{
	// stream for hexadecimal standard output
	ostream hexout(cout.rdbuf());
	hexout.setf(ios::hex, ios::basefield);
	hexout.setf(ios::showbase);

	// switch between decimal and hexadecimal output
	hexout << "hexout: " << 177 << " ";
	cout << "cout: " << 177 << " ";
	hexout << endl;
	hexout << "hexout: " << -49 << " ";
	cout << "cout : " << -49 << " ";
	hexout << endl;

	system("pause");
	return 0;
}