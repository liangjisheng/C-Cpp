
#include "..\..\algostuff.hpp"
using namespace std;

// function object to process the mean value
class MeanValue
{
private:
	long num;		// num of elements
	long sum;		// sum of all element values
public:
	MeanValue() : num(0), sum(0) {}

	// function call
	// process one more element of the sequence
	void operator() (int elem)
	{
		num++;
		sum += elem;
	}

	// return mean value(implicit type conversion)
	operator double() { return static_cast<double>(sum) / static_cast<double>(num); }
};

int main()
{
	vector<int> coll;
	INSERT_ELEMETNS(coll, 1, 8);

	// process and print mean value
	// 返回一元函数(已在算法内部被变动过)的一个副本
	double mv = for_each(coll.begin(), coll.end(), MeanValue());
	cout << "mean value: " << mv << endl;

	system("pause");
	return 0;
}