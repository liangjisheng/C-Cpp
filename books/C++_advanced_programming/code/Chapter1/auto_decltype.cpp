#include <iostream>

using namespace std;

// C++11以来，允许通过拖尾返回类型(trailing return type) 支持一种替代的函数语法
// 这种新语法在普通函数中用的不多，但在指定模板函数的返回类型是非常有用

auto func(int i) -> int
{
    return i + 2;
}


// C++14允许要求编译器自动推断出函数的返回类型，要使用这个功能，需要把auto
// 指定为返回类型，并忽略所有拖尾返回类型
auto divideNumbers(double numerator,double denominator)
{
    if(denominator == 0)
    {
        // print some information
    }
    return numerator / denominator;
    // 函数中可以有多个return语句，甚至可以是递归，但第一个return必须是非递归的
}

auto x = 123;  // x will be of type int
// auto 对较复杂的类型会更有用，auto还可以用于lambda表达式

// 关键字decltype把表达式作为实参，计算出该表达式的类型
int x1 = 123;
decltype(x1) y = 456;   // y will be of type int
// auto和decltype初看似乎并没有增加什么价值，但对于模板而言，
// auto和decltype是非常强大的

auto main() -> int
{
    cout<<func(3)<<endl;

    cout << "Helloworld!" << endl;
    return 0;
}
