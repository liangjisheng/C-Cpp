//**********************************************************************************
//M_swap.cpp
//给出 声明的 函数模版或类模版的成员函数 做具体的函数定义
//**********************************************************************************
#include <iostream>
using namespace std;

template<class T>
void M_swap(T &a,T &b)
{
    T temp;

    temp=a;
    a=b;
    b=temp;
    cout<<"swap completed!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
}