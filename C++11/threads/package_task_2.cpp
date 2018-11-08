#include <iostream>
#include <utility>
#include <future>
#include <thread>

// std::packaged_task::valid
// 检查当前 packaged_task 是否和一个有效的共享状态相关联，对于由默认构造函数生成的
// packaged_task 对象，该函数返回false，除非中间进行了move赋值操作或者swap操作

std::future<int> launcher(std::packaged_task<int(int)>& task, int arg)
{
    if (task.valid())
    {
        std::future<int> ret = task.get_future();
        std::thread (std::move(task), arg).detach();
        return ret;
    }
    else
        return std::future<int>();
}

int main()
{
    std::packaged_task<int(int)> tsk([](int x) { return x*2; });
    std::future<int> fut = launcher(tsk, 25);
    std::cout << "The double of 25 is " << fut.get() << ".\n";

    return 0;
}
