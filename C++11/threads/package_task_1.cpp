#include <iostream>
#include <utility>      // std::move
#include <future>
#include <thread>

int main()
{
    std::packaged_task<int(int)> foo;   // 默认构造函数
    // 使用lambda表达式初始化一个package_task对象
    std::packaged_task<int(int)> bar([](int x) { return x*2; });

    foo = std::move(bar);   // move-赋值操作
    // 获取与 packaged_task 共享状态相关联的 future 对象.
    std::future<int> ret = foo.get_future();

    // 启动一个线程，调用被包装任务
    std::thread(std::move(foo), 10).detach();

    int value = ret.get();  // 等待任务完成并获取结果
    std::cout << "The double of 10 is " << value << ".\n";

    return 0;
}
