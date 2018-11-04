#include <iostream>

using namespace std;

int main()
{
    double f0 = 1.0;
    // mutable允许lambda表达式对以传值变量进行修改
    cout << [=](double f) mutable { return f0 += f; } (-3.5) << endl;
    cout << f0 << endl;

    return 0;
}
