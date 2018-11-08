#include <iostream>
#include <functional>   // std::ref
#include <thread>
#include <future>       // std::promise, std::future

void print_int(std::future<int>& fut)
{
    int x = fut.get();  // 获取共享状态的值
    std::cout << "value: " << x << '\n';
}


int main()
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();   // 和future关联
    std::thread t(print_int, std::ref(fut));    // 将future交给另外一个线程
    prom.set_value(10);;    // 设置共享状态的值，此处和线程t保持同步

    t.join();

    return 0;
}
