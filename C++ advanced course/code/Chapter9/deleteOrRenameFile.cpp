
// C语言实现删除或者重命名文件
#include <iostream>
#include <cstdio>
#include <cerrno>

using namespace std;

int main(int argc, char** argv)
{
	char message[50] = {0};
	if(3 == argc)
	{
		if(rename(argv[1], argv[2]))
		{
			strerror_s(message, 49, errno);
			cerr << "Error:" << message << endl;
			return EXIT_FAILURE;
		}
		else
			cout << argv[1] << " has been renamed to " << argv[2] << endl;
	}
	else if(2 == argc)
	{
		if(remove(argv[1]) == -1)		// remove() return -1 on error
		{
			strerror_s(message, 49, errno);
			cerr << "Error:" << message << endl;
			return EXIT_FAILURE;
		}
		else
			cout << "File " << argv[1] << " removed." << endl;
	}
	else
	{
		cerr << "You must supply a file name to remove." << endl;
		return EXIT_FAILURE;
	}

	system("pause");
	return 0;
}