
// ���Ա�д�Լ��ķº����������ϣ�������ܹ��ͺ������������ʹ�ã��ͱ�������ĳЩ����
// �����ṩһЩ���ͳ�Ա(type members)����ӳ������ͷ���ֵ���ͣ�C++��׼������ṩ��
// һЩ�ṹ����:
// template<class Arg, class Result>
//struct unary_function
//{
//	typedef Arg argument_type;
//	typedef Result result_type;
//};

//template<class Arg1, class Arg2, class Result>
//struct binary_function
//{
//	typedef Arg1 first_argument_type;
//	typedef Arg2 second_argument_type;
//	typedef Result result_type;
//};

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// �Զ���º���
template<class T1, class T2>
struct fopow : public std::binary_function<T1, T2, T1>
{
	T1 operator()(T1 base, T2 exp) const { return std::pow(base, exp); }
};


int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	//transform(coll.begin(), coll.end(),
	//	ostream_iterator<int>(cout, " "),
	//	bind2nd(fopow<int, int>(), 3));		// Error: ambiguous

	// print 3 raised to the power of all element
	transform(coll.begin(), coll.end(),		// source
		ostream_iterator<int>(cout, " "),	// destination
		bind1st(fopow<float, int>(), 3));	// operation
	cout << endl;

	// print all elements raised to the power of 3
	transform(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "),
		bind2nd(fopow<float, int>(), 3));
	cout << endl;

	system("pause");
	return 0;
}
