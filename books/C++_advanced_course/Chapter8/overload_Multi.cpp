
// *是一个一元操作符，作用于指针，表示取指针所指单元的内容，当在某个类中
// 对*操作符进行重载时，是将该类的对象当做一个指针看待,而用*操作符提取指
// 针所指的内容

#include <iostream>

using namespace std;

template<typename T>
class Data_Container
{
	T *p;
public:
	Data_Container(T *inp) { p = inp; }
	~Data_Container() { delete p; }

	// *操作符既可以用友元函数的形式进行重载，也可以用成员函数的形式重载
	template<typename T>
	friend T operator*(const Data_Container<T>&);
};

template<typename T>
T operator*(const Data_Container<T>& src)
{
	return *(src.p);
}

int main()
{
	Data_Container<int> IntData(new int(5));
	Data_Container<double> DoubleData(new double(7.8));
	cout << *IntData << endl;
	cout << *DoubleData << endl;

	system("pause");
	return 0;
}