
// 结构体各个成员变量的内存空间的首地址必须是对齐系数和变量实际长度中较小
// 者的整倍数
// 对于结构体，在其各个数据成员都完成对齐后，结构体本身也需要对齐，及结构体
// 占用的总大小应该为对齐系数和最大数据成员长度中较小值的整数倍

#include <iostream>

using std::cout;
using std::endl;

struct data_test
{
	char	a;
	short	b;
	char	c[2];
	double	d;
	char	e;
	int		f;
	char	g;
}data;

struct data_test1
{
	char	a;
	char	c[2];
	char	e;
	char	g;
	short	b;
	int		f;
	double	d;
};


int main()
{
	cout << sizeof(data) << endl;		// 32
	cout << sizeof(data_test1) << endl;	// 24

	system("pause");
	return 0;
}