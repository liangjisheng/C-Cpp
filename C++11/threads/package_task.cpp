#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// std::package_task包装一个可调用对象，并且允许异步获取该可调用对象产生的结果
// 从包装可调用对象意义上来讲，std::packaged_task 与 std::function 类似，
// 只不过 std::packaged_task 将其包装的可调用对象的执行结果传递给一个
// std::future对象(该对象通常在另外一个线程中获取std::packaged_task任务的执行结果

// std::package_task对象内部包含了两个最基本元素,一个是被包装的任务，任务(task)
// 是一个可调用的对象，如函数指针、成员函数指针或者函数对象, 另一个是共享状态(shared state)
// 用于保存任务的返回值，通过std::future 对象来达到异步访问共享状态的效果

int countdown(int from, int to)
{
    for (int i = from; i != to; --i)
    {
        std::cout << i << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Finished!\n";
    return from - to;
}

int main()
{
    std::packaged_task<int(int, int)> task(countdown);
    std::future<int> ret = task.get_future();   // 获得与package_task共享状态相关联的future对象
    std::thread th(std::move(task), 10, 0);
    int value = ret.get();  // 共享状态不是ready状态的时候，调用future.get()的线程会阻塞
    std::cout << "The countdown lasted for " << value << " seconds.\n";
    th.join();

    return 0;
}
