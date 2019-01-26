
#include <iostream>
#include <direct.h>		// _getcwd()
#include <errno.h>

using std::cout;
using std::endl;

int main()
{
	char filePath[256] = {0};
	char *forcestr = NULL;
	// ��ǰ����Ŀ¼
	_getcwd(filePath, 255);
	cout << filePath << endl;
	// �������Ч����ͬ,��һ������ΪNULLʱ�ڲ������·�����ȵ���
	// malloc()����ռ�,��·�����붯̬����Ŀռ��У������˺�һ��
	// Ҫ�ͷţ����������ڴ�й¶
	forcestr = _getcwd(NULL, 0);
	cout << forcestr << endl;
	if(forcestr)
	{
		free(forcestr);
		forcestr = NULL;
	}

	// �ı����Ĺ���Ŀ¼�������Ϊ��Ŀ¼
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