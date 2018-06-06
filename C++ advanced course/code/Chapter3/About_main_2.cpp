
// 系统在提交命令行参数时，会自动在数组argv[]的最后一个有效参数后面加一个空指针
// 可以利用空指针推断出命令行中有多少个参数

#include <iostream>

using std::endl;
using std::cout;

int main(int argc, char* argv[])
{
	int i = 0;
	while(argv[i])
		cout << argv[i++] << endl;
	cout << "argc = " << argc << endl;
	cout << "i = " << i << endl;

	system("pause");
	return 0;
}