#include <iostream>
#include <thread>
#include <future>

std::promise<int> prom;

void print_global_promise()
{
    // get_future()返回一个与promise对象共享状态相关联的future
    std::future<int> fut = prom.get_future();
    int x = fut.get();  // 获取共享状态的值
    std::cout << "value: " << x << '\n';
}


int main()
{
    std::thread th1(print_global_promise);
    prom.set_value(10); // 设置共享状态的值，此后promise的共享状态标志变为ready
    th1.join();

    prom = std::promise<int>(); // prom被移动赋值为一个新的promise对象
    std::thread th2(print_global_promise);
    prom.set_value(20);
    th2.join();

    return 0;
}
