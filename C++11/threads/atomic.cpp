#include <iostream>
#include <atomic>   // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>

// 不能写成std::atomic<int> foo = 0;因为拷贝构造函数被禁用
std::atomic<int> foo(0);

void set_foo(int x)
{
    foo = x;    // 调用std::atomic::operator=()
}

void print_foo()
{
    while (0 == foo)    // wait while 0 == foo
        std::this_thread::yield();
    std::cout << "foo: " << foo << '\n';
}


int main()
{
    std::thread first(print_foo);
    std::thread second(set_foo, 10);

    first.join();
    second.join();

    return 0;
}
