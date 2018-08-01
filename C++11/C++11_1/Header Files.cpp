
// C++标准程序库中的标识符都定义在namespace std中
// #include<iostream>
// 从操作系统的角度看，新头文件命名方式并不意味着标注头文件
// 没有扩展名，如何处理由编译器决定，C++系统可以自动添加一个
// 扩展名.自己写的头文件最好加上.h以区分标准头文件

// 标准异常类(standard exception classes),语言本身或标准程序库
// 抛出的所有异常，都派生自基类exception，这是其他数个标准异常
// 类的基类，标准异常类分位3组
// 1:语言本身支持的异常
// 2:C++标准程序库抛出的异常
// 3:程序作用域(scope of a program)之外发出的异常

// 1:语言本身支持的异常
// new失败后抛出bad_alloc异常
// dynamic_cast失败时抛出bad_cast异常
// RTTI过程中，如果传给typeid()的参数为0或空指针时抛出bad_typeid异常
// 发生非预期的异常抛出bad_exception,bad_exception调用unexpected()

// 2:C++标准程序库抛出的异常
// C++标准库异常派生自logic_error
// invalid_argument,length_error,out_of_range
// domain_error(专业领域范畴内的错误)
// 标准IO提供了一个ios_base::failure的特殊异常，当数据流(data stream)
// 由于错误或由于到达文件尾端而发生状态改变时，就可能抛出异常

// 3:程序作用域(scope of a program)之外发出的异常
// range_error,overflow_error,underflow_error

#include<exception>			// for exception bad_exception
#include<new>	// for bad_alloc
#include<typeinfo>	// for bad_cast bad_typeid
#include<stdexcept>	// 其它异常
#include<ios>		// for ios_base::failure

// C++标准程序库在许多地方采用特殊对象来处理内存配置和寻址，这样
// 的对象称为配置器(allocator).配置器体现出一种特定的内存模型(memory model)
// 如果运用多个不同的配置器对象，便可以在同一个程序中采用不同的内存模型