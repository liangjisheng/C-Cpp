
// for_each()可以返回其仿函数，这也，可以通过for_each()的返回值来获取仿函数的状态了
// 使用for_each()来处理一个序列的平均值

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function object to process the mean value
class MeanValue
{
private:
	long num;	// number of elements
	long sum;	// sum of all element value
public:
	MeanValue() : num(0), sum(0) {}

	// function call process one or more element of the sequence
	void operator() (int elem)
	{
		num++;			// increment count
		sum += elem;	// add value
	}

	// return mean value
	double value() { return static_cast<double>(sum) / static_cast<double>(num); }

	// 自动类型转换函数，类MeanValue可以隐式转换为double
	operator double() { return static_cast<double>(sum) / static_cast<double>(num); }
};


int main()
{
	vector<int> coll;

	// insert elements from 1 to 8
	for (int i = 1; i <= 8; ++i)
		coll.push_back(i);

	// process and print mean value
	// 返回的仿函数赋值给mv，然后便可存取其状态
	MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
	cout << "mean value: " << mv.value() << endl;

	// 调用隐式类型转换
	cout << "mean value: " << mv << endl;

	system("pause");
	return 0;
}
