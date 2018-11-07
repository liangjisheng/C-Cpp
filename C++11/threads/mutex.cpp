#include <iostream>
#include <thread>
#include <mutex>

volatile int counter(0);       // non-atomic counter
std::mutex mtx;     // locks access to counter

void attempt_10k_increases()
{
    for (int i = 0; i < 10000; ++i)
    {
        // only increase if currently not locked
        if (mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}

void sure_10k_increases()
{
    for (int i = 0; i < 10000; ++i)
    {
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}

int main()
{
    std::thread ths[10];
    for (int i = 0; i < 10; ++i)
        ths[i] = std::thread(attempt_10k_increases);
    for (auto& th : ths)
        th.join();
    std::cout << counter << " successful increases of the counter.\n";

    counter = 0;
    for (int i = 0; i < 10; ++i)
        ths[i] = std::thread(sure_10k_increases);
    for (auto& th : ths)
        th.join();
    std::cout << counter << " successful increases of the counter.\n";

    return 0;
}
