#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::timed_mutex mtx;

void fireworks()
{
    // waiting to get a lock: each thread prints "-" every 200ms
    while (!mtx.try_lock_for(std::chrono::milliseconds(200)))
        std::cout << "-";

    // got a lock! - wait for 1s, the this thread prints "*"
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*\n";
    mtx.unlock();
}

int main()
{
    std::thread ths[10];
    // spawn 10 threads
    for (int i = 0; i < 10; ++i)
        ths[i] = std::thread(fireworks);
    for (auto& th : ths)
        th.join();

    return 0;
}
