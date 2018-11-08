#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;     // 标志位

void do_print_id(int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    // 调用wait(lck)函数会阻塞当前线程，同时wait()函数会自动调用lck.unlock()释放锁，
    // 使得其他被阻塞在锁竞争上的线程得以继续执行.
    // 另外，一旦当前线程获得通知(notified,通常是另外某个线程调用notify_*唤醒了当前线程),
    // wait()函数会自动调用lck.lock()，使得lck的状态和wait函数被调用时相同
    while (!ready)
        cv.wait(lck);

    // 线程被唤醒，继续往下执行
    std::cout << "thread " << id << '\n';
}

void go()
{
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();    // 唤醒所有线程
}

int main()
{
    std::thread ths[10];
    for (int i = 0; i < 10; ++i)
        ths[i] = std::thread(do_print_id, i);

    std::cout << "10 threads ready to race...\n";
    go();

    for (auto& th : ths)
        th.join();

    return 0;
}
