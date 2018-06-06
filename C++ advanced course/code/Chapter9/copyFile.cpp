
// �ı��ļ�Ҳ�����ö������ļ��򿪣��˳�����ö������ļ���д�ķ�ʽ
// ʵ���ļ��ĵĿ��ٿ���,�˳������Ƕ��ı��ļ����Ƕ������ļ�����
// ��������

#include <iostream>
#include <fstream>

using std::ios_base;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


int main(int argc, char** argv)
{
	const static int BUF_SIZE = 4096;
	if(argc != 3)
	{
		cout << "Usage: copy source file target file" << endl;
		return 1;
	}

	ifstream in(argv[1], ios_base::in | ios_base::binary);
	ofstream out(argv[2], ios_base::out | ios_base::binary);
	// �������ز�����!���жϴ򿪻򴴽��ļ��Ĳ����Ƿ�ɹ�
	if(!in || !out)
	{
		cout << "opening or creating file failed" << endl;
		return 1;
	}

	char buf[BUF_SIZE] = {0};
	do 
	{
		in.read(buf, BUF_SIZE);
		out.write(buf, in.gcount());
	} while (in.gcount() > 0);

	in.close();
	out.close();
		
	system("pause");
	return 0;
}