
// C++IO流类库中，整型状态字state表示输入输出状态,
// goodbit = 0x00
// eofbit = 0x01		// 输入流结束
// failbit = 0x02		// 流操作失败
// badbit = 0x04		// 流操作非法
// hardfail = 0x08		// IO出现致命错误,流不可恢复

// rdstate()将返回当前的状态字，根据状态字中各位的位置情况，了解当前
// IO操作的状态

// 直接利用读取状态字的办法来判断当前IO操作状态的例子程序
#include <iostream>
#include <fstream>

using namespace std;

void test_rdstate()
{
	ifstream ifs;
	// 如果文件不存在,则failbit标志会被设置
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

// 统计一个文本文件中有多少个空格
// 使用提取操作(>>)无法从流中读取空格
// windows系统下文本文件中的回车实际上在文件中占用了两个字节0x0a0d
// 使用get()读取时,只会返回一个0x0a;只有get()函数读到文件末尾，函数
// eof()才会返回1，get()读到的最后一个字符是-1,这是文件结束的标志
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

// 对于流，只要出错，相应的状态就会设置为1，此后忽略所以对该流对象的操作
// 必须用clear()清0，然后才能正常运行