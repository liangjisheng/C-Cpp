#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

std::atomic<bool> ready(false);     // can be checked without begin set
std::atomic_flag winner = ATOMIC_FLAG_INIT;  // always set when checked


void count1m(int id)
{
    while (!ready)
        std::this_thread::yield();  // 等待主线程中设置ready为true

    for (int i = 0; i < 1000000; ++i);
    // 如果某个线程率先执行完上面的计数过程，测试winner为false,返回false并将winner设置为true
    // 此后其他线程执行test_and_set时,if语句判断为false,因此不会输出自己的id
    if (!winner.test_and_set())
        cout << "thread#" << id << " won\n";
}


int main()
{
    vector<thread> ths;
    cout << "spawing 10 threads that count to 1 million..\n";
    for (int i = 0; i < 10; ++i)
        ths.push_back(thread(count1m, i));
    ready = true;

    for (auto& th : ths)
        th.join();

    return 0;
}
