
// for_each()���Է�����º�������Ҳ������ͨ��for_each()�ķ���ֵ����ȡ�º�����״̬��
// ʹ��for_each()������һ�����е�ƽ��ֵ

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

	// �Զ�����ת����������MeanValue������ʽת��Ϊdouble
	operator double() { return static_cast<double>(sum) / static_cast<double>(num); }
};


int main()
{
	vector<int> coll;

	// insert elements from 1 to 8
	for (int i = 1; i <= 8; ++i)
		coll.push_back(i);

	// process and print mean value
	// ���صķº�����ֵ��mv��Ȼ���ɴ�ȡ��״̬
	MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
	cout << "mean value: " << mv.value() << endl;

	// ������ʽ����ת��
	cout << "mean value: " << mv << endl;

	system("pause");
	return 0;
}
