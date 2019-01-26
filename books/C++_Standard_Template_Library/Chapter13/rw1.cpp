
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// open file "example.dat" for reading and writing
	filebuf buffer;				// �ļ�����������filebuf��class basic_filebuf<>�����ַ�����char���ػ�ʵ��
	ostream output(&buffer);	// ���ļ�����������װ��һ��������Ϲ���һ������ļ���
	istream input(&buffer);		// ���ļ�����������װ��һ���������Ϲ���һ�������ļ���
	buffer.open("example.dat", ios::in | ios::out | ios::trunc);

	for (int i = 1; i <= 4; ++i)
	{
		// write one line
		output << i << ". line" << endl;

		// print all file contents
		input.seekg(0);	// seek to the beginning
		cout << input.rdbuf();	// ���������е�Ч��һ��
		//char c;
		//while (input.get(c))
		//	cout.put(c);
		cout << endl;
		input.clear();	// clear eofbit and failbit
	}

	system("pause");
	return 0;
}