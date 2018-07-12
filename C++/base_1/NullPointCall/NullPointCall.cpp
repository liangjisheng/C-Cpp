
#include <iostream>
#include "NullPointCall.h"

using std::cout;
using std::endl;

int CNullPointCall::m_nStatic = 0;

void CNullPointCall::test1() { cout << m_nStatic << endl; }

void CNullPointCall::test2() { cout << "Very Cool!" << endl; }

void CNullPointCall::test3(int nNum) { cout << nNum << endl; }

void CNullPointCall::test4() { cout << m_nNum << endl; }


void test_CNullPointCall()
{
	CNullPointCall::test1();	// 通过类调用静态函数

	CNullPointCall *pNull = NULL;
	pNull->test1();				// 通过实例调用静态函数
	pNull->test2();
	pNull->test3(3);
	// pNull->test4();
}

// 对于类成员函数而言，并不是一个对象对应一个单独的成员函数体，而是此类的所有对象
// 共用这个成员函数体。 当程序被编译之后，此成员函数地址即已确定。而成员函数之所以
// 能把属于此类的各个对象的数据区别开, 就是靠这个this指针。函数体内所有对类数据成员
// 的访问， 都会被转化为this->数据成员的方式

// 一般的函数参数是直接压入栈中（push 0Dh），而this指针却被放到了ecx寄存器中
// 在类的非成员函数中如果要用到类的成员变量，就可以通过访问ecx寄存器来得到指
// 向对象的this指针，然后再通过this指针加上成员变量的偏移量来找到相应的成员变量
