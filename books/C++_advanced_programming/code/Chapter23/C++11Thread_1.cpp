
// ����������Ϊĳ���̵߳��̺߳���
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class Counter
{
public:
	Counter(int id, int numIterations) 
		: mId(id), mNumIterations(numIterations)
	{}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i)
		{
			cout << "Coutner " << mId << " has value ";
			cout << i << endl;
		}
	}

private:
	int mId;
	int mNumIterations;
};


class Counter1
{
public:
	Counter1() {}
	void operator()()
	{
		for (int i = 0; i < 10; ++i)
			cout << i << endl;
	}
};


// main����ʾ��ͨ�����������ʼ���̵߳�3�з�����
// �����������Ǹ��Ƶ��̵߳�ĳ���ڲ��洢�С����Ҫ�ں��������ĳ���ض�ʵ��
// ��ִ��operator()���ǽ��и��ƣ���ôӦ��ʹ��<functional>ͷ�ļ��е�
// std::ref()ͨ�����ô����ʵ��
int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{1, 20} };
	// Using named variable
	Counter c(2, 12);
	thread t2(c);
	// Using temporary object
	thread t3(Counter(3, 10));

	// ���ʹ��Բ���Ŷ�����ʹ��ͳһ��ʼ���б���������Ὣ������һ��
	// ����Ϊt4����������������һ��thread�����������һ��ָ�룬��ָ��
	// ����һ��Counter1������޲κ�������˽���ʹ��ͳһ��ʼ���﷨�����
	// ��������֧��ͳһ��ʼ���﷨��������Ӷ����Բ���ţ��Է�ֹ������
	// ���������Ϊ�������� thread t4((Counter1())); Ϊ��ȷ������һ��
	// �̶߳���
	thread t4((Counter1()));

	// Wait for threads to finish
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	system("pause");
	return 0;
}

