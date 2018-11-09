#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int cargo = 0;

void consumer()
{
    std::unique_lock<std::mutex> lck(mtx);
    while (0 == cargo)
        cv.wait(lck);

    std::cout << cargo << '\n';
    cargo = 0;
}

void producer(int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    cargo = id;
    cv.notify_one();
}


int main()
{
    std::thread consumers[10], producers[10];
    for (int i = 0; i < 10; ++i)
    {
        consumers[i] = std::thread(consumer);
        producers[i] = std::thread(producer, i + 1);
    }

    for (int i = 0; i < 10; ++i)
    {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}
