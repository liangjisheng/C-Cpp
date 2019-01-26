
// 由于析构函数没有参数，因此始终可以自动调用父类的析构函数，
// 析构函数的调用顺序刚好与构造函数相反
// (1)调用本类的析构函数
// (2)销毁本类的数据成员，与创建的顺序相反
// (3)如果有父类，调用父类的析构函数
// 可以递归使用这些规则。类链上最底层的成员总是被第一个销毁。
// 所有的析构函数都声明为virtual

// 编译器生成的默认析构函数不是virtual,因此应该定义自己的虚析构函数，
// 至少在父类中应该这么做 

#include <iostream>

using namespace std;

class Something{
public:
    Something() { cout << "2"; }
    ~Something() { cout << "2"; }		// should be virtual ,but will work
};

class Parent{
public:
    Parent() { cout << "1"; }
    ~Parent() { cout << "1"; } 			// BUG! make this virtual 
};

class Child : public Parent {
public:
    Child() { cout << "3"; }
    ~Child() { cout << "3"; }			// should be virtual ,but will work
private:
    Something mDataMember;
};

int main()
{
    Parent* ptr = new Child();
    delete ptr;

	system("pause");
    return 0;
}

