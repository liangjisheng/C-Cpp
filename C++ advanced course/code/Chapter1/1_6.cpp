
// 常对象与常函数

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class A
{
    int num;
public:
    A() { num = 5; }
    // 只有类的非静态成员函数可以被声明为常函数，
    // 其他类型的函数(如外部函数)不能被声明为常函数
    // 两个disp函数构成重载，他们最终会被编译器看成是
    // void disp(A*), void disp(const A*)
    void disp();
    void disp() const;
    void set(int n) { num = n; }
};

void A::disp() const
{
    cout << num << endl;
}

void A::disp()
{
    cout << "Another version of disp()" << endl;
}


int main()
{
    A a1;
    a1.set(3);
    // 首先寻找非const版本，如果没有找到，在调用的他的const版本
    a1.disp();              // not const

    A const a2;
    a2.disp();             // const

    // 调用a1对象的const版本的disp(),建立a1对象的常引用或者常指针
    ((const A&)a1).disp();
    // or
    ((const A*)&a1)->disp();

    system("pause");
    return 0;
}
