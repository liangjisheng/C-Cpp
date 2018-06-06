
#include <iostream>
#include <direct.h>

using namespace std;

int create(int argc, char** argv)
{
	char message[50] = {0};
	if(argc < 2)
	{
		cerr << "Usage:" << argv[0] << "[new dir name]\n";
		return EXIT_FAILURE;
	}

	if(_mkdir(argv[1]) == -1)	// Create the directory
	{
		strerror_s(message, 49, errno);
		cerr << "Error:" << message << endl;
		return EXIT_FAILURE;
	}
}

int del(int argc, char** argv)
{
	char message[50] = {0};
	if(argc < 2)
	{
		cerr << "Usage:" << argv[0] << "[dir name]" << endl;
		return EXIT_FAILURE;
	}

	if(_rmdir(argv[1]) == -1)		// Remove the directory
	{
		strerror_s(message, 49, errno);
		cerr << "Error:" << message << endl;
		return EXIT_FAILURE;
	}
}


int main(int argc, char** argv)
{
	// create(argc, argv);
	del(argc, argv);
	system("pause");
	return 0;
}