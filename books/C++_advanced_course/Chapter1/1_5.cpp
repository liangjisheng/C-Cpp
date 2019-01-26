
// 很多情况先，为了表达同一种语义，可以将const放在不同的位置，
// 但在某些情况下，const只能放在特定的位置，否则意义就会完全不一样
// const 配合二重指针的例子

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

int main()
{
    // 下面的这两个声明二级指针是不一样的
    // p1不是指针常量，它所指向的变量类型是int const*(指向整型常量的指针)
    // p2也不是指针常量，它所指向的变量是指针常量(int* const，即指向整型的指针常量)
    // 所以p1和p2的赋值时有讲究的
    int const **p1;
    int* const *p2;
    int i = 5;
    int j = 6;
    const int * ptr1 = &i;  // int to const int
    int * const ptr2 = &j;  // int* to const int*

    p1 = &ptr1;
    p2 = &ptr2;
    // p1 = &ptr2;              // error
    // p2 = &ptr1;              // error

    cout << **p1 << endl;
    cout << **p2 << endl;

    system("pause");
    return 0;
}
