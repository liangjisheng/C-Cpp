
// 模板的非类型参数并不是只能实例化为文字常量，它也可以被实例化为在编译阶段能
// 够静态计算的任何表达式

#include <iostream>

using std::cout;
using std::endl;

template<typename T, T *Total, int *Number>
class Single
{
	T single_value;
public:
	Single(T s)
	{
		single_value = s;
		(*Total) += s;
		(*Number)++;
	}
};

// 全局变量的地址可以看做常量，可以用来实例化模板的非类型参数
int Int_Total;
int Int_Number;
double Dbl_Total;
int Dbl_Number;


int main()
{
	// 用3,6,9来初始化一个对象数组
	Single<int, &Int_Total, &Int_Number> arr_int[3] = {3, 6, 9};
	Single<double, &Dbl_Total, &Dbl_Number> arr_dbl[4] = {1.1, 2.2, 4.4, 8.8};
	cout << "The number of integers is: " << Int_Number << endl;
	cout << "The total value of integers is: " << Int_Total << endl;
	cout << "The number of double is: " << Dbl_Number << endl;
	cout << "The total value of double is: " << Dbl_Total << endl;

	system("pause");
	return 0;
}

