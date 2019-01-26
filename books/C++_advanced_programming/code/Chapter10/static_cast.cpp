#include <iostream>

using namespace std;

class Base{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    virtual ~Derived() {}
};

int main()
{
    Base* b;
    Derived* d = new Derived();
    b = d;  // Don't need a cast to go up the inheritance hierarchy
    d = static_cast<Derived*>(b);   // Need a cast to go down the hierarchy
    Base base;
    Derived derived;
    Base& br = derived;
    Derived& dr = static_cast<Derived&>(br);

    // 这种类型转换可以用于指针和引用，而不适用于对象本身
    // static_cast类型转换不执行运行期间的类型检测。它允许将任何
    // Base指针转换为Derived指针，或者将Base引用转换为Derived引用
    // 哪怕在运行时Base实际上并不是一个Derived,也是如此
    // 下面的代码可以正常编译并执行，但是使用指针d可能导致灾难性
    // 的结果，包括内存重写超出了对象的边界
    Base* b1 = new Base();
    Derived* d1 = static_cast<Derived*>(b);
    // dynamic_cast执行运行期间的类型检测

    return 0;
}
