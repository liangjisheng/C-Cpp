
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>

int main()
{
	char path[_MAX_PATH] = {0};
	_getcwd(path,_MAX_PATH);
	printf("当前工作目录:\n%s\n",path);
	if((_chdir("D:\\vs2010_projects")) == 0)
	{
		printf("修改路径成功\n");
		_getcwd(path,_MAX_PATH);
		printf("当前工作目录:\n%s\n",path);
	}
	else
	{
		printf("修改路径失败.\n");
		exit(1);
	}

	system("pause");
	return 0;
}