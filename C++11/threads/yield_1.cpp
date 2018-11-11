#include <iostream>
#include <chrono>
#include <thread>

// yield:当前线程放弃执行，操作系统调度另一线程继续执行,比如说你的线程需要
// 等待某个操作完成，如果你直接用一个循环不断判断这个操作是否完成就会使得这个
// 线程占满CPU时间，这会造成资源浪费。这时候你可以判断一次操作是否完成，
// 如果没有完成就调用yield交出时间片，过一会儿再来判断是否完成，这样这个线程
// 占用CPU时间会大大减少

using std::cout;
using std::endl;

void little_sleep(std::chrono::microseconds us)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do {
        std::this_thread::yield();
    } while (std::chrono::high_resolution_clock::now() < end);
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    little_sleep(std::chrono::microseconds(100));
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    cout << "wait for "
         << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
         << " microseconds.\n";

    return 0;
}
