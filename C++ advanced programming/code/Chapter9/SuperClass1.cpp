
// 对象并不是突然建立起来的，创建对象必须同时创建父类和包含于其中的对象
// C++定义了如下的创建顺序:
// (1)如果某个类具有基类，执行基类的默认构造函数。除非在ctor-initializer
// 中调用了基类的构造函数，此时调用这个构造函数，而不是默认构造函数
// (2)类的非静态数据成员按照声明的顺序创建
// (3)执行该类的构造函数，
// 可以递归使用这些规则

#include <iostream>

using namespace std;

class Something{
public:
    Something() { cout << "2"; }
};

class Parent{
public:
    Parent() { cout << "1"; }
};

class Child : public Parent {
public:
    Child() { cout << "3"; }
private:
    Something mDataMember;
};

int main()
{
    Child myChild;          // print 123

    return 0;
}
