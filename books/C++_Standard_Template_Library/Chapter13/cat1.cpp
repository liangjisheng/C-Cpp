
#include <fstream>
#include <iostream>

using namespace std;

// for all file names passed as command-line arguments
// open print contents, and close file

int main(_In_ int argc, char* argv[])
{
	ifstream file;

	for (int i = 1; i < argc; ++i)
	{
		// open 不会清除任何状态标志
		file.open(argv[i]);

		// write file contents to cout
		char c;
		while (file.get(c))
			cout.put(c);

		// clear eofbit and failbit set due to end-of-file
		file.clear();

		file.close();
	}
}