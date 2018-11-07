#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mtx;

void print_thread_id(int id)
{
    mtx.lock();
    // 有3种Tag标记，std::adopt_lock，std::defer_lock，std::try_to_lock
    // 传入std::adopt_lock表明当前线程已经获得了锁
    std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
    std::cout << "thread #" << id << '\n';
}

int main()
{
    std::thread ths[10];
    for (int i=0; i<10; ++i)
        ths[i] = std::thread(print_thread_id, i+1);
    for (auto& th : ths)
        th.join();

    return 0;
}
