
// C++IO������У�����״̬��state��ʾ�������״̬,
// goodbit = 0x00
// eofbit = 0x01		// ����������
// failbit = 0x02		// ������ʧ��
// badbit = 0x04		// �������Ƿ�
// hardfail = 0x08		// IO������������,�����ɻָ�

// rdstate()�����ص�ǰ��״̬�֣�����״̬���и�λ��λ��������˽⵱ǰ
// IO������״̬

// ֱ�����ö�ȡ״̬�ֵİ취���жϵ�ǰIO����״̬�����ӳ���
#include <iostream>
#include <fstream>

using namespace std;

void test_rdstate()
{
	ifstream ifs;
	// ����ļ�������,��failbit��־�ᱻ����
	ifs.open("1.txt");
	if(ifs.rdstate() == ios::eofbit)
		cout << "End of file" << endl;
	if(ifs.rdstate() == ios::badbit)
		cout << "Fatal I/O error" << endl;
	if(ifs.rdstate() == ios::failbit)
		cout << "Non-fatal I/O error" << endl;
	if(ifs.rdstate() == ios::goodbit)
		cout << "No error" << endl;
	ifs.close();
}

// ͳ��һ���ı��ļ����ж��ٸ��ո�
// ʹ����ȡ����(>>)�޷������ж�ȡ�ո�
// windowsϵͳ���ı��ļ��еĻس�ʵ�������ļ���ռ���������ֽ�0x0a0d
// ʹ��get()��ȡʱ,ֻ�᷵��һ��0x0a;ֻ��get()���������ļ�ĩβ������
// eof()�Ż᷵��1��get()���������һ���ַ���-1,�����ļ������ı�־
void test_eof()
{
	ifstream ifs("1.txt");
	char ch = '\0';
	int counter = 0;
	while(!ifs.eof() && !ifs.fail())
	{
		ch = ifs.get();
		if(ch == ' ') 
			counter++;
		cout << (int)ch << endl;
	}
	cout << counter << endl;
	ifs.close();
}

void test_1()
{
	char str[256] = {0};
	int i = 0;
	cout << "input a integer:";
	cin >> i;
	while(cin.fail())
	{
		cout << "state:" << cin.rdstate() << endl;
		cin.clear(0);
		cin.getline(str, 255);
		cout << "input error,input integer again:";
		cin >> i;
	}
	cin.getline(str, 255);
	cout << "input string:";
	cin.getline(str, 255);

	cout << "integer = " << i << endl;
	cout << "string = " << str << endl;
}

int main()
{
	// test_eof();
	test_1();

	system("pause");
	return 0;
}

// ��������ֻҪ������Ӧ��״̬�ͻ�����Ϊ1���˺�������ԶԸ�������Ĳ���
// ������clear()��0��Ȼ�������������