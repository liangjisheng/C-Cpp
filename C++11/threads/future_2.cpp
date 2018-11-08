#include <iostream>
#include <future>
#include <utility>  // std::move

int do_get_value() { return 11; }


int main()
{
    // 由默认构造函数创建的 std::future 对象,
    // 初始化时该 std::future 对象处于为 invalid 状态.
    std::future<int> foo, bar;
    foo = std::async(do_get_value); // move赋值，foo变为valid
    bar = std::move(foo);   // move赋值， bar变为valid,foo变为invalid.

    if (foo.valid())
        std::cout << "foo's value: " << foo.get() << '\n';
    else
        std::cout << "foo is not valid.\n";

    if (bar.valid())
        std::cout << "bar's value: " << bar.get() << '\n';
    else
        std::cout << "bar is not valid.\n";

    return 0;
}
