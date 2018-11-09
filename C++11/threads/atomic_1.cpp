#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> foo(0);

void set_foo(int x)
{
    // 设置(store)原子对象foo的值
    foo.store(x, std::memory_order_relaxed);
}

void print_foo()
{
    int x;
    do {
        // 读取(load)原子对象foo的值
        x = foo.load(std::memory_order_relaxed);
    } while (0 == x);

    std::cout << "foo: " << x << '\n';
}

int main()
{
    std::thread first(print_foo); // 线程 first 打印 foo 的值
    std::thread second(set_foo, 10); // 线程 second 设置 foo 的值
    first.join();
    second.join();

    return 0;
}
