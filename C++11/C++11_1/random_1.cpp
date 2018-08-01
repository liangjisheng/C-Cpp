
// C++11提供的<random>实现了随机数库，它通过随机数引擎类(random_number_engines)产生随机数序列
// 随机数分布类(random_number distribution)使用随机数引擎生成服从特定概率分布的随机数
#include <iostream>
#include <random>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

using std::vector;
using std::string;
using std::normal_distribution;

void test_1()
{
	default_random_engine e;
	// 使用默认的随机数引擎种子，每次生成的序列都是一样的
	for (size_t i = 0; i < 10; ++i)
		cout << e() << endl;
	cout << endl;
	cout << "Min random:" << e.min() << endl; //输出该随机数引擎序列的范围 
	cout << "Max random:" << e.max() << endl;
}

void test_2()
{
	default_random_engine e;	// 或者直接在这里改变种子e(10)
	e.seed(10);		// 设置新的种子
	for (size_t i = 0; i < 10; ++i)
		cout << e() << endl;
	cout << endl;
	cout << "Min random:" << e.min() << endl; //输出该随机数引擎序列的范围 
	cout << "Max random:" << e.max() << endl;
}

void test_3()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);	// 随机数分布对象
	for (size_t i = 0; i < 10; ++i)		// 生成范围0-9的随机数序列
		// 分布对象将随机数引擎作为参数，分布对象使用引擎参数生成随机数，
		// 并将其映射到指定分布
		cout << u(e) << ' ';
	cout << endl;

	cout << u.min() << endl;
	cout << u.max() << endl;
}

void test_4()
{
	default_random_engine e;
	uniform_real_distribution<double> u(0, 1); //随机数分布对象 
	for (size_t i = 0; i < 5; ++i)  //生成范围为0.0-1.0的随机数序列 
		cout << u(e) << " ";
	cout << endl;

	cout << u.min() << endl;
	cout << u.max() << endl;
}

void test_5()
{
	default_random_engine e;
	vector<unsigned> vals(9);
	normal_distribution<> n(4, 1.5);	// 正态分布，均值为4，标准差为1.5
	for (size_t i = 0; i != 200; ++i)
	{
		unsigned v = lround(n(e));		// 舍入到最近整数
		if (v < vals.size())
			++vals[v];					// 统计0-8数字出现的次数
	}

	for (decltype(vals.size()) i = 0; i != vals.size(); ++i)
		cout << i << ": " << string(vals[i], '#') << endl;
}

int main()
{
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	test_5();

	system("pause");
	return 0;
}