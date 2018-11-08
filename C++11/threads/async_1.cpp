#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;

void do_print_ten(char c, int ms)
{
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        cout << c;
    }
}


int main()
{
    cout << "with launch::async:\n";
    std::future<void> foo = std::async(std::launch::async, do_print_ten, '*', 100);
    std::future<void> bar = std::async(std::launch::async, do_print_ten, '@', 200);

    // async "get" (wait for foo and bar to be ready)
    foo.get();
    bar.get();
    cout << endl;

    cout << "with launch::deferred:\n";
    foo = std::async(std::launch::deferred, do_print_ten, '*', 100);
    bar = std::async(std::launch::deferred, do_print_ten, '@', 200);

    // deferred "get" (perform the actual calls)
    // 调用get()的时候，异步任务才开始执行
    foo.get();  // 任务执行的时候，主线程会在此阻塞
    bar.get();
    cout << endl;

    return 0;
}
