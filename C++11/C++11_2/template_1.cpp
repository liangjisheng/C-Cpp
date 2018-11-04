#include <iostream>

using namespace std;

template <typename T, typename U, int value>
class SuckType
{
public:
    T a;
    U b;
    SuckType() : a(value), b(value) {}
};

// 可以使用typedef为类型定义一个新的名称，但却没有办法为模板定义一个新的名称
// C++11中使用using
template <typename T>
using NewType = SuckType<int, T, 1>;

// 定义一个函数模板
template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y)
{
    return x + y;
}

// C++11中可以指定模板的默认参数
template <typename T = int, typename U = int>
auto add_1(T x, U y) -> decltype(x + y)
{
    return x + y;
}


int main()
{

    return 0;
}
