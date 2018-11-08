#include <iostream>
#include <future>   // std::async, std::future, std::shared_future

int do_get_value() { return 10; }

int main()
{
    std::future<int> fut = std::async(do_get_value);
    // share()返回一个shared_future对象，调用该函数后，fut对象本身已经不再和任何
    // 共享状态相关联，因此fut的状态不在是valid的了。
    std::shared_future<int> shared_fut = fut.share();

    // 共享的future对象可以被多次访问
    std::cout << "value: " << shared_fut.get() << '\n';
    std::cout << "its double: " << shared_fut.get() * 2 << '\n';

    return 0;
}
