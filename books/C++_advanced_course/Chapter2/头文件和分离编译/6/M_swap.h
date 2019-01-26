
#ifndef M_SWAP_H_INCLUDED
#define M_SWAP_H_INCLUDED

template<class T>
void M_swap(T &a,T &b);

//为了成功地对模版进行实例化，编译器必须能够使用相应的函数定义
//故 需要在头文件中直接给出函数的具体定义  但这样一般会导致头文件
//较长，而且模版的定义和实现混合在一起，不利于维护

//可用另一种办法，那便是
#include "M_swap.cpp"
//在头文件中用预处理指令#include包含实现文件

#endif