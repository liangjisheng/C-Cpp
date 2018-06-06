
// 测试window下栈空间大小的程序

#include <iostream>
#include <iomanip>

using namespace std;

int *addr;
int count;

// 启动了一个没有出口的递归调用序列，没向下递归一层，都要在栈上申请空间
// 每次申请空间的大小可以从参变量i的相邻两次地址变化得到，程序会一直运行到
// 堆栈溢出
void func(int i )
{
	cout << count << " : " << (int)addr - int(&i) << endl;
	count++;
	addr = &i;
	func(i);
}

int main()
{
	int i;
	addr = &i;
	func(2);

	system("pasue");
	return 0;
}