
#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

int main()
{
	char str[10] = "ABC����";		// ռ7���ֽ�
	cout << sizeof(str) << endl;
	char *p = str;
	for(int i = 0; i < 10; i++)
		cout << (int)*p++ << " ";
	cout << endl;
	for(int i = 0; i < 10; i++)
		cout << (int)str[i] << " ";
	cout << endl;

	wchar_t wstr[20]  = L"ABC����";
	cout << sizeof(wstr) << endl;
	p = (char*)wstr;
	for(int i = 0; i < 20; i++)
		cout << (int)*p++ << " ";
	cout << endl;
	for(int i = 0; i < 20; i++)
		cout << (int)wstr[i] << " ";
	cout << endl;

	ofstream ofs("file1.txt");
	ofs << str;
	ofs.close();

	wofstream wofs("file2.txt");
	// ��Ȼ�������ļ�����������locale,����ֻ�Ǳ�֤��wchar_t
	// ���͵��ַ���(�е������ַ�)�ܹ���������ļ���,������Ȼ
	// ���ն��ֽ��ַ����ı������,����file1.txt��file2.txt�ļ�
	// �����ݺʹ�С����һ����,����7���ֽ�
	wofs.imbue(locale("CHS"));
	wofs << wstr;
	wofs.close();

	ofs.open("file3.txt");
	short flag = 0xFEFF;		// Unicode�����־
	// ���ļ��Ŀ�ͷ�Զ�����дһ��Unicode�����־
	ofs.write((char*)&flag, sizeof(short));
	// �Զ����Ʒ�ʽ��wchar_t���͵��ַ���д���ļ�
	ofs.write((char*)wstr, wcslen(wstr) * 2);
	ofs.close();

	system("pause");
	return 0;
}