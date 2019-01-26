#include <iostream>

using namespace std;

// 每个函数都有一个预定义的局部变量__func__
// static const char __func__[] = "function-name"
// 可以将这个变量用于日志

int addNumber(int a,int b)
{
    cout<<"Entering function: "<<__func__<<endl;
    return a + b;
    // cout<<"Exit function: "<<__func__<<endl;
}

int main()
{
    cout<<"Entering function: "<<__func__<<endl;
    int sum = addNumber(3,4);
    cout<<"sum(3,4)="<<sum<<endl;
    cout<<"Exit function"<<__func__<<endl;

    return 0;
}
