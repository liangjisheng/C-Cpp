#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex foo, bar;

void task_a()
{
    std::lock(foo, bar);    // simultaneous lock (同时锁住两个互斥量)
    std::unique_lock<std::mutex> lck1(foo, std::adopt_lock);
    std::unique_lock<std::mutex> lck2(bar, std::adopt_lock);
    std::cout << "task a\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    // unlocked automatically on destruction of lck1 and lck2
}

void task_b()
{
    // foo.lock(), bar.lock();  // replace by:
    std::unique_lock<std::mutex> lck1, lck2;
    lck1 = std::unique_lock<std::mutex>(bar, std::defer_lock);
    lck2 = std::unique_lock<std::mutex>(foo, std::defer_lock);
    std::lock(lck1, lck2);
    std::cout << "task b\n";
    // unlocked automatically on destruction of lck1 and lck2
}

int main()
{
    std::thread th1 (task_a);
    std::thread th2 (task_b);

    th1.join();
    th2.join();

    return 0;
}
