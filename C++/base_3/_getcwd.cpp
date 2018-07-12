
// 获得当前工作目录的绝对路径

#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>

void test_1()
{
	char path[_MAX_PATH] = {0};
	_getcwd(path, _MAX_PATH);
	printf("当前工作目录\n%s\n", path);
	memset(path, 0, _MAX_PATH);

	if(0 == (_chdir("D:\\")))
	{
		printf("修改工作路径成功\n");
		_getcwd(path, _MAX_PATH);
		printf("当前工作目录\n%s\n", path);
		memset(path, 0, _MAX_PATH);
	}
	else
	{
		perror("修改工作路径失败\n");
		exit(-1);
	}
}


int main()
{
	test_1();

	getchar();
	return 0;
}