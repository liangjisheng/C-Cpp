#include <iostream>
#include <string>
using namespace std;

const string message = "test";

const string& foo(){
    return message;     // const string To const string&
}

int main()
{
    // auto 去除了引用和const限定符,所以f1是string类型
    // 建立了一个副本
    auto f1 = foo();

    // 如果希望f1是一个const引用，就可以明确将它建立为一个
    // 一个引用,并标记为const
    const auto& f2 = foo();     // f2 is const string& 类型
    // 另一中方法是使用decltype，它没有去除任何限定符
    decltype(foo()) f3  = foo();   // f3 与f2的类型一致

    // 但上面的代码有重复的地方，foo()需要指定两次，
    // 当foo()是一个比较复杂的表达式是，会比较繁琐
    // C++14中解决如下:
    decltype(auto) f4 = foo();
    // f4也是const string& 类型

    return 0;
}
