
// 显示一个文件的信息,文件的大小、文件的创建时间、上一次的修改时间

#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>

using std::cout;

int main(int argc, char** argv)
{
	struct stat fileInfo;
	char message[30] = {0};
	if(argc < 2)
	{
		cout << "Usage: fileInfo<file name>\n";
		return EXIT_FAILURE;
	}
	// Use stat() to get the info
	if(stat(argv[1], &fileInfo) != 0)
	{
		strerror_s(message, 29, errno);
		std::cerr << "Error:" << message << std::endl;
		return EXIT_FAILURE;
	}

	cout << "Type		:";
	if((fileInfo.st_mode & S_IFMT) == S_IFDIR )		// From sys/types.h
		cout << "Directory\n";
	else
		cout << "File\n";
	cout << "Size		:" << fileInfo.st_size << "\n";		// Size in bytes
	cout << "Device		:" << (char)(fileInfo.st_dev + 'A') << '\n';	// Device number
	ctime_s(message, 29, &fileInfo.st_ctime);	// 里面本身包含一个换行
	cout << "Created	:" << message;		// Creation time
	ctime_s(message, 29, &fileInfo.st_mtime);	// 里面本身包含一个换行
	cout << "Modified	:" << message;		// Last mod time

	system("pause");
	return 0;
}