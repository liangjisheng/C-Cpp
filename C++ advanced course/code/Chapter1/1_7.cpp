
// const 修饰函数的参数和返回值

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

void disp1(const int &ri)
{
    cout << ri << endl;
}

// 传值调用的形参声明为常量，虽然语法上没有什么错误，但并没有多大的
// 实用价值，因为形参i是否在函数体内改变，并不影响实参的值
void disp2(const int i)
{
    cout << i << endl;
}

// 当函数返回普通数据而不是引用时，用const修饰函数返回值并没有多大
// 的价值，这时函数的返回值是一个非左值，本来就不能够改变其值
const int disp3(const int &ri)
{
    cout << ri << endl;
    return ri;
}

// 可以修改返回引用的被引用对象的值
int & disp4(int &ri)
{
    cout << ri << endl;
    return ri;
}

// 如果函数返回值为引用，用const修饰返回值可以阻止被引用对象的修改
const int &disp5(const int &ri)
{
    cout << ri << endl;
    return ri;
}


int main()
{
    int n = 5;
    disp1(n);
    disp2(n);
    disp3(n);
    disp4(n) = 6;
    disp5(n);           // 返回类型为const int& 所以不能赋值

    system("pause");
    return 0;
}
