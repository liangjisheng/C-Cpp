
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;
using std::vector;
using std::once_flag;
using std::call_once;

once_flag gOnceFlag;

void initializeSharedResource()
{
	// ... Initialize shared resources that will be used by multiple threads
	cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
	// Make sure the shared resources are initialized
	call_once(gOnceFlag, initializeSharedResource);
	// ... Do some work, including using the shared resources
	cout << "Processing" << endl;
}


int main()
{
	// Launch 3 threads
	vector<thread> threads(3);
	for (auto& t : threads)
		t = thread{ processingFunction };

	// Join on all threads
	for (auto& t : threads)
		t.join();

	// 3���߳�ִֻ����һ��initializeSharedResource���ڵ���call_once()��
	// �����У������̱߳�������ֱ��initializeSharedResource����

	system("pause");
	return 0;
}