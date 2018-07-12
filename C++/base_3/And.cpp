
// 把一个整数做与运算,会把该整数最右边的一个1变成0
// 根据此,可以计算一个正数中二进制1的个数

#include <iostream>

using std::cout;
using std::endl;

// 计算一个正数中二进制1的个数
int count(unsigned int n)
{
	size_t num = 0;
	while(n)
	{
		n &= (n - 1);
		num++;
	}

	return num;
}

// 输入两个整数m,n计算需要改变m的二进制中的多少位才能得到n
// 解决方法：求这两个数的异或(统计不同的位数)，统计异或结果中1的位数
int ChangeCount(int a, int b)
{
	int c = a ^ b;
	int diffnum = 0;
	while(c)
	{
		c &= (c - 1);
		diffnum++;
	}

	return diffnum;
}

// 用一条语句判断一个整数是不是2的整数次方
// 如果一个整数是2的整数次方，那么它的二进制表示中有且只有1位是1
// 而其他所有位都是0
bool isPowInt(int x)
{
	// x & (x - 1)将二进制x中最右边的1变为0
	return !(x & (x - 1));
}


int main()
{
	unsigned int n = 0x0a;
	cout << count(n) << endl;

	cout << ChangeCount(n, 1) << endl;

	cout << isPowInt(0x10) << endl;

	system("pause");
	return 0;
}