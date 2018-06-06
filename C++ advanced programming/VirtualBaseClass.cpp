#include <iostream>

using namespace std;

//virtual基类的存在需要特别处理。一个类的对象以另一个对象为初值进行构造时，
//而后者拥有一个virtual基类子对象，那么会使bitwise copy semantics失效。
//每个编译器都会让派生类对象中的virtual基类子对象的位置在执行期间准备妥当
//（如G++把virtual基类子对象放在派生类对象的末端），而bitwise copy semantics(逐位复制)
//可能会破坏该这个位置，所以编译器必须在它自己合成出来的复制构造函数中做出判断。

class Base{
public:
    Base() { mBase = 100; }
    virtual ~Base() {}
    virtual void print() {}
private:
    int mBase;
};

class VBase : virtual public Base{
public:
    VBase() { mVBase = 101; }
    virtual ~VBase(){}
    virtual void print() {}
    int mVBase;
};

class Derived : public VBase{
public:
    Derived() { mDerived = 102; }
    virtual ~Derived() {}
    virtual void print() {}
    int mDerived;
};

int main()
{
    // 如果一个类的对象与该类的另一个对象为初值进行构造，
    // 那么使用bitwise copy semantics即可完成相关的操作。
    VBase vb1;
    VBase vb2 = vb1;

    // 问题仍然是发生在以一个派生类的对象作为其基类对象的初值进行初始化时。
    // 在这种情况下，为了完全正确地完成vb的初值的设定，编译器必须合成一个
    // 复制构造函数，安插一些代码，来完成根据派生类的对象完成其基类对象
    // 部分成员变量的初始化，并正确设定的基类的vptr的值。
    Derived d;
    VBase vb = d;

    int *p = (int*)&d;
    for(size_t i = 0; i < sizeof(d) / sizeof(int); ++i){
        cout << *p << endl;
        ++p;
    }

    p = (int*)&vb;
    cout << endl;
    for(size_t i = 0; i < sizeof(vb) / sizeof(int); ++i){
        cout << *p << endl;
        ++p;
    }

    Base b;
    cout << endl;
    p = (int*)&b;
    for(size_t i = 0; i < sizeof(vb) / sizeof(int); ++i){
        cout << *p << endl;
        ++p;
    }

    return 0;
}
