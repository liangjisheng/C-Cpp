
// 引用被声明为常引用(或者指针被声明为指向常量的指针)，只是说明不能
// 通过改引用(或该指针)去修改被引用对象(或被指向单元)的值。至于被引用
// 对象原来是什么性质，或者是否会被其它引用修改，是无法由常引用(或常指针)
// 来决定的。

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 5;
    // const 修饰只是说明不能通过ri常引用来修改i的值，
    // 但并没有阻止通过其它方式来修改i的值
    const int &ri = i;
    cout << ri << endl;
    int *p = &i;
    *p = 6;
    cout << ri << endl;
    i = 7;
    cout << ri << endl;

    return 0;
}
