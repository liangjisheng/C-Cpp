#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available() { return cargo != 0; }

// 消费者线程
void consume(int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::unique_lock<std::mutex> lck(mtx);
        // template <class Predicate>
        // void wait (unique_lock<mutex>& lck, Predicate pred);
        // 只有当pred为false时调用wait才会阻塞当前线程，并且在收到其他线程的通知后
        // 只有当pred为true时才会解除阻塞
        cv.wait(lck, shipment_available);
        std::cout << cargo << '\n';
        cargo = 0;
    }
}


int main()
{
    std::thread consumer_thread(consume, 10);

    // 主线程为生产者线程，生产10个产品
    for (int i = 0; i < 10; ++i)
    {
        while (shipment_available())
            std::this_thread::yield();
        std::unique_lock<std::mutex> lck(mtx);
        cargo = i + 1;
        cv.notify_one();
    }

    consumer_thread.join();

    return 0;
}
