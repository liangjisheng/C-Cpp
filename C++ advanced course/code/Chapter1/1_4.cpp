
#include <iostream>
#include <stdlib.h>         // for system("pause");

using namespace std;

int main()
{
    int i = 5;
    const int v1 = 1;
    int const v2 = 2;
    const int *p1 = NULL;
    int const *p2 = NULL;

    // 编译错误
    // const * int p3;
    // error conversion from const int* to int*
    // int * const p3 = &v1;
    // 编译错误
    // int* const p3;

    // int* to const int* is ok
    int* const p3 = &i;
    const int* const p4 = &v1;      // ok
    int const * const p5 = &v2;     // ok

    const int &r1 = v1;             // ok
    int const &r2 = v2;             // ok

    // error 没有常量引用
    // const & int r3;              // error

    // errro because of const
    // int & const r4 = i;

    cout << *p4 << endl;

    system("pause");
    return 0;
}
