// C++11中，使用noexcept来替换throw()
// C++11中，默认将delete函数设置成noexcept
// C++11中，类的析构函数默认也是noexcept(true)的，如果程序员显示的为析构函数
// 指定了noexcept,或者类的基类或者成员有noexcept(false)的析构函数，此类的
// 析构函数就不在保持默认值

#include <iostream>

using namespace std;

struct A
{
    ~A()   { throw 1; }
};

struct B
{
    // noexcept(false)表明析构函数有可能抛出异常
    ~B() noexcept(false) { throw 2; }
};

struct C
{
    B b;
};

void funcA() { A a; }
void funcB() { B b; }
void funcC() { C c; }

int main()
{
    try {
        funcB();
    }
    catch(...) {
        cout << "caught funcB." << endl;
    }

    try {
        funcC();
    }
    catch(...) {
        cout << "caught funcC." << endl;
    }

    try {
        funcA();    // terminate called after throwing an instance 'int'
    }
    catch(...) {
        cout << "caught funcA." << endl;
    }

    return 0;
}
