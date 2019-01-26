
// 文件可分为两种，一种是驻留在磁盘或其它外部介质上的一个有序数据集，可以是
// 数据文件、可执行程序等；另一种是设备文件，是指和主机相连的各种设备，像
// 显示器、键盘、打印机等；外部设备一般可看做一个文件来进行管理，把他们的输入、
// 输出等同于对磁盘文件的读和写。
// 在C语言中，文件的类型可分为两种：缓冲型和非缓冲型。文件系统的读写因此也分为
// 两种方法：缓冲文件系统一般用来处理文本文件；非缓冲文件系统可用来处理二进制
// 文件


// char* tmpnam(char* pszname);
// 创建一个临时文件名(注意：仅仅产生一个文件名)，将他放在pszname指向的C风格
// 字符串中。常量L_tmpnam和TMP_MAX限制了文件名包含的字符串数以及确保当前目录
// 中不生成重复文件名的情况下。tmpname()可被调用的最多次数。


#include <iostream>
#include <cstdio>

int main()
{
	using namespace std;
	cout << "This system can generate up tp " << TMP_MAX 
		<< " temporary names of up to " << L_tmpnam << " characters.\n";

	char pszname[L_tmpnam] = {0};
	cout << "Here are ten names: \n";
	for(int i = 0; i < 10; i++)
	{
		tmpnam(pszname);
		cout << pszname << endl;
	}

	system("pause");
	return 0;
}