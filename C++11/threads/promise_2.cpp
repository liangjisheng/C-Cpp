#include <iostream>
#include <functional>   // std::ref
#include <thread>
#include <future>       // std::promise, std::future
#include <exception>    // std::exception, std::current_exception()

void get_int(std::promise<int>& prom)
{
    int x;
    std::cout << "Please, enter an integer value: ";
    std::cin.exceptions(std::ios::failbit); // throw on failbit

    try {
        std::cin >> x;   // sets failbit if input is not int
        prom.set_value(x);
    } catch (std::exception&) {
        // 设置异常后，promise的共享状态标志变为ready
        prom.set_exception(std::current_exception());
    }
}

void print_int(std::future<int>& fut)
{
    try {
        int x = fut.get();
        std::cout << "value: " << x << '\n';
    } catch (std::exception & e) {
        std::cout << "[exception caught: ]" << e.what() << "]\n";
    }
}


int main()
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    // th1从终端接收一个整数，th2将该整数打印出来，如果th1接收一个非整数，则为
    // promise设置一个异常(failbit), th2在std::future::get时抛出该异常
    std::thread th1(get_int, std::ref(prom));
    std::thread th2(print_int, std::ref(fut));

    th1.join();
    th2.join();

    return 0;
}
