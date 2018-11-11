#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

// yield()调用线程放弃执行，回到准备状态，重新分配cpu资源。
// 所以调用该方法后，可能执行其他线程，也可能还是执行该线程

std::mutex mtx; // 互斥访问控制台输出

std::atomic<bool> ready(false);

void count1m(int id)
{
    while (!ready)
        std::this_thread::yield();
    for (volatile int i = 0; i < 1000000; ++i) {}

    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "thread#" << id << '\n';
}

int main()
{
    std::thread ths[10];
    std::cout << "race of 10 threads that count to 1 million.\n";
    for (int i = 0; i < 10; ++i)
        ths[i] = std::thread(count1m, i);
    ready = true;   // go
    for (auto& th : ths) th.join();
    std::cout << '\n';

    return 0;
}
