
// lambda��ʾ���ܺܺõ����ڱ�׼C++�߳̿�

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;


int main()
{
	int id = 1;
	int numIterations = 5;
	thread t1(
		[id, numIterations] {
		for (int i = 0; i < numIterations; ++i)
		{
			cout << "Counter " << id << " has value ";
			cout << i << endl;
		}
	}
	);

	t1.join();

	system("pause");
	return 0;
}
