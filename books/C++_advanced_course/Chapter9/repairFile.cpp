
// ͨ���ļ�ָ��Ķ�λ���޸�ĳ���Ѿ����ڵ��ļ��еĲ�������

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char arr[] = "ABCDABCD";
	ofstream out("1.bin", ios_base::out | ios_base::binary);
	int nLen = strlen(arr);
	out.write(arr, nLen);
	out.close();

	char c = '\0';
	ios::streampos position;
	fstream fout("1.bin", ios::in | ios::binary);
	fout.seekp(0L, ios::end);
	position = fout.tellp();
	fout.seekp(0L, ios::beg);
	cout << position << endl;

	// ����ʹ��fout.eof()���ж��Ƿ�ﵽ�ļ���ĩβ����Ϊ����������ļ�
	// ��ĩβ�ط�ִ��һ�ζ�ȡ����������ȷ���Ƿ�ﵽ�ļ�ĩβ������ʱ
	// �п��ܶ�ȡ���ַ��������'A',���������µ�д�붯�������ڴ������ļ�
	// ʹ��eof()����������ͬʱ�ɶ�д���ļ���Ӧ�ò���������ʽ�ж��ļ�
	// �Ƿ����
	while(fout.tellp() != position)
	{
		fout.read(&c, 1);
		cout << fout.tellp() << endl;
		if(c == 'A')
		{			
			c = '0';
			fout.write(&c, 1);
			fout.seekp(-1L, ios::cur);
		}
	}

	fout.close();

	system("pause");
	return 0;
}