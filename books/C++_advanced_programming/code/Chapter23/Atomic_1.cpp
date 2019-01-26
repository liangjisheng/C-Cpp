
// ԭ����������ԭ�ӷ��ʣ�����ζ�Ų���Ҫ�����ͬ�����ƾͿ���ִ�в����Ķ�д
// ������û��ԭ�Ӳ���������һ�������Ͳ����̰߳�ȫ�ģ���Ϊ���������Ƚ�ֵ
// ���ڴ���ص��Ĵ����У����������ٰѽ��������ڴ棬��һ���߳̿����ڵ���
// ������ִ�й����нӴ������ڴ棬����һ������������

#include <iostream>
#include <atomic>		// ԭ�Ӳ���
#include <ratio>		// ������
#include <chrono>		// ʱ��
#include <thread>
#include <vector>


using std::cout;
using std::endl;
using std::thread;
using namespace std::chrono;
using std::ratio;
using std::vector;
using std::atomic;


// δʹ��ԭ������
void func(int& counter)
{
	for (int i = 0; i < 100; ++i)
	{
		++counter;
		// ����һС���ӳ�
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


// ԭ������
void func_atomic(atomic<int>& counter)
{
	for (int i = 0; i < 100; ++i)
	{
		// ��ԭ������ִ��++counter��������һ��ԭ�������У�
		// ����ֵ������ֵ��������ֵ��������̲��ᱻ���
		++counter;
		// �ӳ�1����
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


int main()
{
	int counter = 0;
	vector<thread> threads;
	for (int i = 0; i < 10; ++i)
		threads.push_back(thread{ func, std::ref(counter) });

	for (auto& t : threads)
		t.join();

	// δʹ��ԭ�����ͣ��ڴ��Ľ����1000,��ִ�г���Ľ��ȴ����1000��
	// ��ʾ���̵߳ľ�������������ʹ��ԭ�����ͽ��
	cout << "Result = " << counter << endl;


	atomic<int> counter_atomic(0);
	vector<thread> threads_atomic;
	for (int i = 0; i < 10; ++i)
		threads_atomic.push_back(thread{ func_atomic, std::ref(counter_atomic) });

	for (auto& t : threads_atomic)
		t.join();

	// ʹ��ԭ�����ͣ��ڴ����Ϊ1000��ʵ�ʳ���ִ�еĽ��Ϊ1000
	cout << "Result_atomic = " << counter_atomic << endl;

	system("pause");
	return 0;
}