#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;
std::timed_mutex timed_mtx;

void print_thread_id(int id)
{
    std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
    // 调用它所管理的 Mutex 对象的 lock 函数。如果在调用  Mutex 对象的 lock 函数时
    // 该 Mutex 对象已被另一线程锁住，则当前线程会被阻塞，直到它获得了锁
    lck.lock();
    std::cout << "thread #" << id << '\n';
    lck.unlock();
}

void print_star()
{
    std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
    // 上锁操作，调用它所管理的 Mutex 对象的 try_lock 函数，如果上锁成功，则返回 true，否则返回 false
    // print '*' if successfully locked, 'x' otherwise:
    if (lck.try_lock())
        std::cout << '*';
    else
        std::cout << 'x';
}

void fireworks()
{
    std::unique_lock<std::timed_mutex> lck(timed_mtx, std::defer_lock);
    // waiting to get a lock: each thread prints '-' every 200ms
    while (!lck.try_lock_for(std::chrono::milliseconds(200)))
        std::cout << '-';

    // got a lock! - wait for 1s, then this thread prints "*"
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "*\n";
}


int main()
{
    std::thread ths[10];
    for (int i=0; i<10; ++i)
        ths[i] = std::thread(print_thread_id, i+1);
    for (auto& th : ths)
        th.join();
    std::cout << '\n';

    std::thread ths_1[10];
    for (int i=0; i<10; ++i)
        ths_1[i] = std::thread(print_star);
    for (auto& th : ths_1)
        th.join();
    std::cout << '\n';

    std::thread ths_2[10];
    for (int i=0; i<10; ++i)
        ths_2[i] = std::thread(fireworks);
    for (auto& th : ths_2)
        th.join();
    std::cout << '\n';

    return 0;
}
