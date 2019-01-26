
// 遍历指定目录，只能遍历此目录下的目录或文件，
// 而不能遍历子目录和子目录下的文件
#include <stdio.h>
#include <string.h>
#include <io.h>

int main(void)
{
	_finddata_t fileDir;
	char dir[256] = {0};
	printf("input the point directory:\n");
	scanf("%s",&dir);
	printf("%s\n",dir);
	printf("\n");
	long lfDir;

	int pathLen = strlen(dir);
	if('\\' != dir[pathLen - 1])
		strcat(dir,"\\");

	strcat(dir,"*.*");

	if((lfDir = _findfirst(dir,&fileDir)) == -1l)
		printf("No file is found\n");
	else
	{
		printf("file list:\n");
		do{
			printf("%s\n",fileDir.name);
		}while(_findnext(lfDir,&fileDir) == 0);
	}
	_findclose(lfDir);

	getchar();
	return 0;
}