#include <iostream>
#include <utility>      // for pair<>
#include <tuple>        // for tuple<>
#include <typeinfo>     // for typeid

using namespace std;

int main()
{
    // pair<>类可以保存两个值，每个值都有特定的类型。
    // 每个值的类型在编译时确定
    // 如果没有用string定义对象的话，不包含string头文件
    // 代码也可以正确的编译，链接，运行
    pair<int ,string> p1(16, "hello");
    pair<bool, float> p2(true, 1.23f);
    cout << "p1 = (" << p1.first << ", " << p1.second << ")" << endl;
    cout << "p2 = (" << p2.first << ", " << p2.second << ")" << endl;

    // tuple是pair的泛化，允许存储任意数量的值，每个值都有自己
    // 特定的类型。也是编译时确定
    using myTuple = tuple<int, string, bool>;
    myTuple t1(1, "test", true);
    // std::get<i>获得第i个元素
    cout << "t1 = (" << get<0>(t1) << ", " << get<1>(t1)
        << ", " << get<2>(t1) << ")" << endl;

    cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;

    return 0;
}
