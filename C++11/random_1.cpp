
// C++11�ṩ��<random>ʵ����������⣬��ͨ�������������(random_number_engines)�������������
// ������ֲ���(random_number distribution)ʹ��������������ɷ����ض����ʷֲ��������
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
	// ʹ��Ĭ�ϵ�������������ӣ�ÿ�����ɵ����ж���һ����
	for (size_t i = 0; i < 10; ++i)
		cout << e() << endl;
	cout << endl;
	cout << "Min random:" << e.min() << endl; //�����������������еķ�Χ 
	cout << "Max random:" << e.max() << endl;
}

void test_2()
{
	default_random_engine e;	// ����ֱ��������ı�����e(10)
	e.seed(10);		// �����µ�����
	for (size_t i = 0; i < 10; ++i)
		cout << e() << endl;
	cout << endl;
	cout << "Min random:" << e.min() << endl; //�����������������еķ�Χ 
	cout << "Max random:" << e.max() << endl;
}

void test_3()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);	// ������ֲ�����
	for (size_t i = 0; i < 10; ++i)		// ���ɷ�Χ0-9�����������
		// �ֲ����������������Ϊ�������ֲ�����ʹ��������������������
		// ������ӳ�䵽ָ���ֲ�
		cout << u(e) << ' ';
	cout << endl;

	cout << u.min() << endl;
	cout << u.max() << endl;
}

void test_4()
{
	default_random_engine e;
	uniform_real_distribution<double> u(0, 1); //������ֲ����� 
	for (size_t i = 0; i < 5; ++i)  //���ɷ�ΧΪ0.0-1.0����������� 
		cout << u(e) << " ";
	cout << endl;

	cout << u.min() << endl;
	cout << u.max() << endl;
}

void test_5()
{
	default_random_engine e;
	vector<unsigned> vals(9);
	normal_distribution<> n(4, 1.5);	// ��̬�ֲ�����ֵΪ4����׼��Ϊ1.5
	for (size_t i = 0; i != 200; ++i)
	{
		unsigned v = lround(n(e));		// ���뵽�������
		if (v < vals.size())
			++vals[v];					// ͳ��0-8���ֳ��ֵĴ���
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