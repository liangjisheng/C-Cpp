
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// _getch()和_getche()库函数，可以实现不带缓冲的输入，因为不带缓冲
// 所以也来不及对输入进行任何格式化操作，所以不带缓冲的输入总是针对
// 单个字符进行的

int main()
{
	char c[7] = {0};
	cout << "Please input password:";
	int nIndex = 0;
	while(nIndex < 6)
	{
		// 每输入一个字符，都立即被读入内存，并且在标准输出设备上不会
		// 有回显字符
		char tmp = _getch();
		if((tmp > 'a' && tmp < 'z') 
			|| (tmp > 'A' && tmp < 'Z') 
			|| (tmp > '0' && tmp < '9'))
		{
			c[nIndex++] = tmp;
			cout << '*';
		}
	}
	//for(int i = 0; i < 6; i++)
	//{
	//	c[i] = _getch();
	//	cout << '*';
	//}
	cout << endl;
	
	if(string(c) == "123456")
		cout << "right" << endl;
	else
		cout << "wrong" << endl;

	system("pause");
	return 0;
}