
#include <iostream>
#include <direct.h>		// _getcwd()
#include <errno.h>

using std::cout;
using std::endl;

int main()
{
	char filePath[256] = {0};
	char *forcestr = NULL;
	// 当前工作目录
	_getcwd(filePath, 255);
	cout << filePath << endl;
	// 与上面的效果相同,第一个参数为NULL时内部会根据路径长度调用
	// malloc()分配空间,将路径存入动态申请的空间中，不过此后一定
	// 要释放，否则会造成内存泄露
	forcestr = _getcwd(NULL, 0);
	cout << forcestr << endl;
	if(forcestr)
	{
		free(forcestr);
		forcestr = NULL;
	}

	// 改变程序的工作目录，将其改为父目录
	if(_chdir(".."))
	{
		switch(errno)
		{
		case ENOENT:
			cout << "Unable to locate the directory" << endl;
			break;
		case EINVAL:
			cout << "Invalid buffer" << endl;
			break;
		default:
			cout << "Unknown error.\n" << endl;
		}
	}
	else
	{
		forcestr = _getcwd(NULL, 0);
		cout << forcestr << endl;
		if(forcestr)
		{
			free(forcestr);
			forcestr = NULL;
		}
	}

	system("pause");
	return 0;
}