#include <iostream>

using namespace std;

void DefineArray(const int n)
{
    int B[n] = {};
    cout << B[0] << endl;
}

int main()
{
    const int m = 5;
    int A[m] = {};
    cout << A[0] << endl;
    DefineArray(4);

    // 文字常量是不可寻址的，所以下面会编译错误
    // int &r = 5;          // 编译错误

    // 这里实际上有一个将文字常量转化为常变量的过程。即现在数据区
    // 开辟一个值为5的无名整型量，然后将引用r与这个整型量进行绑定
    const int &r = 5;         // ok

    // cout << "Hello world!" << endl;
    //system("pause");
    return 0;
}
