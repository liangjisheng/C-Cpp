
#include <iostream>
#include <fstream>

void printFileTwice(const char* filename)
{
	std::ifstream file(filename);

	// print contents the first time,��ʱֱ�Ӳ��������壬������ı���״̬
	std::cout << file.rdbuf();

	// seek to the beginning
	file.seekg(0);

	// print contents the second time
	std::cout << file.rdbuf();
}

int main(int argc, char* argv[])
{
	// print all files passed as a command-line argument twice
	for (int i = 1; i < argc; ++i)
		printFileTwice(argv[i]);

	system("pause");
	return 0;
}
