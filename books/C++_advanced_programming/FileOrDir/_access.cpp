// �ж��ļ��Ƿ����
#include <iostream>
#include <io.h>			// for _access(const char* filename, int amode);

using std::cout;
using std::endl;

int main()
{
	// _access(const char* filename, int amode);
	// amode:
	// 0: ����ļ��Ƿ����
	// 2: ����ļ��Ƿ��д����
	// 4: ����ļ��Ƿ�ɶ�����
	// 6: ����ļ��Ƿ�ɶ�д����

	char szFile[] = "D:\\JPG\\0.jpg";

	if(_access(szFile, 0) != -1)
	{
		cout << "file exist." << endl;

		/*if(_access(szFile, 1) != -1)
			cout << "file is a execute file." << endl;
		else
			cout << "file is not a execute file." << endl;*/

		if(_access(szFile, 2) != -1)
			cout << "file has write permission." << endl;
		else
			cout << "file hasn't write permission." << endl;

		if(_access(szFile, 4) != -1)
			cout << "file has read permission." << endl;
		else
			cout << "file hasn't read permission." << endl;

		if(_access(szFile, 6) != -1)
			cout << "file has read and write permission." << endl;
		else
			cout << "file hasn't read and write permission." << endl;
	}
	else
		cout << "file not exist." << endl;

	system("pause");
	return 0;
}