#include <iostream>
#include <thread>
#include <atomic>
#include <list>

using namespace std;

std::atomic_bool bIsReady(false);
std::atomic_int iCount(100);

void threadfun1()
{
    if (!bIsReady)
        this_thread::yield();
    while (iCount > 0)
        cout << "iCount: " << iCount-- << endl;
}

int main()
{
    list<thread> listThread;
    for (int i = 0; i < 10; ++i)
        listThread.push_back(thread(threadfun1));

    for (auto& th : listThread)
        th.join();

    return 0;
}
