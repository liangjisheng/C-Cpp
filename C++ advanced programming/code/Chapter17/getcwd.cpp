
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>

int main()
{
	char path[_MAX_PATH] = {0};
	_getcwd(path,_MAX_PATH);
	printf("��ǰ����Ŀ¼:\n%s\n",path);
	if((_chdir("D:\\vs2010_projects")) == 0)
	{
		printf("�޸�·���ɹ�\n");
		_getcwd(path,_MAX_PATH);
		printf("��ǰ����Ŀ¼:\n%s\n",path);
	}
	else
	{
		printf("�޸�·��ʧ��.\n");
		exit(1);
	}

	system("pause");
	return 0;
}