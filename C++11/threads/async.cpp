#include <iostream>
#include <future>
#include <chrono>
#include <cmath>

using std::cout;
using std::endl;

double ThreadTask(int n)
{
    cout << std::this_thread::get_id()
         << " start computing..." << endl;

    double ret = 0;
    for (int i = 0; i <= n; ++i)
        ret += std::sin(i);

    cout << std::this_thread::get_id()
         << " finished computing..." << endl;
    return ret;
}


int main()
{
    // 指定启动策略，异步执行，任务会在另一个线程中执行，
    // std::launch::deferred: 异步任务将会在共享状态被访问时调用，相当与按需调用（即延迟(deferred)调用）
    std::future<double> f(std::async(std::launch::async, ThreadTask, 100000000));
#if 0
    while (f.wait_until(std::chrono::system_clock::now() + std::chrono::seconds(1))
           != std::future_status::ready)
        cout << "task is running...\n";
#else
    while(f.wait_for(std::chrono::seconds(1)) != std::future_status::ready)
        cout << "task is running...\n";
#endif

    cout << f.get() << endl;

    return 0;
}
