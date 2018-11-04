#include <iostream>

using namespace std;

// C++11中引入了委托构造的概念，这使得构造函数可以在同一个类中一个构造函数调用
// 另一个构造函数，达到简化代码的目的
class Base
{
public:
    int value1;
    int value2;
    Base() { value1 = 1; }
    Base(int value) : Base()    // 委托 Base() 构造函数
    {
        value2 = 2;
    }
};


int main()
{

    return 0;
}
