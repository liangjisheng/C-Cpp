#include <iostream>

using namespace std;

int main()
{
    // 前置++是在原来的变量上直接改变，后置的话是想将+1之后的值
    // 保存在一个局部变量里，原来的变量用完后在赋值给原来的变量
    int i = 2;
    int res = ++i + ++i;
    cout << res << endl;        // 8
    cout << "i = " << i << endl << endl;    // 4

    i = 2;
    res = ++i + i++;
    cout << res << endl;        // 6
    cout << "i = " << i << endl << endl;    // 4

    i = 2;
    res = i++ + ++i;
    cout << res << endl;        // 6
    cout << "i = " << i << endl << endl;    // 4

    i = 2;
    res = i++ + i++;
    cout << res << endl;        // 5
    cout << "i = " << i << endl << endl;    // 4

    return 0;
}
