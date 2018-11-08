#include <iostream>
#include <utility>
#include <future>
#include <thread>
#include <chrono>

// std::packaged_task::reset()
// 重置 packaged_task 的共享状态

int triple(int x) { return x*3; }

int main()
{
    std::packaged_task<int(int)> tsk(triple);
    std::future<int> fut = tsk.get_future();
    std::thread(std::move(tsk), 100).detach();
    std::cout << "The triple of 100 is " << fut.get() << ".\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    // re-use same task object
    tsk.reset();
    fut = tsk.get_future();
    std::thread(std::move(tsk), 200).detach();
    std::cout << "The triple of 200 is " << fut.get() << ".\n";

    return 0;
}
