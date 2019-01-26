#include <iostream>

using namespace std;

// 引用默认为const,无法改变引用所指对象

// 定义数组时，数组的大小必须是一个常量表达式，
// const int getArraySize() { return 32; }

// 可以使用constexpr关键重新定义getArraySize()函数，
// 把它变成常量表达式，常量表达式在编译是计算。
constexpr int getArraySize() { return 32; }

// 通过定义constexpr构造函数，可以创建用户自定义类型的常量
// 表达式变量。constexpr构造函数应该满足一下要求:
// 构造函数的所有参数都应该是字面量类型
// 构造函数体不应该是function-try-block
// 构造函数应该满足于constexpr函数相同的要求
// 所有数据成员都应该用常量表达式初始化
class Rect{
public:
    constexpr Rect(int width,int height)
    : mWidth(width),mHeight(height) {}
    constexpr int getArea() const { return mWidth * mHeight; }
private:
    int mWidth,mHeight;
};

int main()
{
    //int& unnamedRef1 = 5;               // Does not compile
    const int& unnamedRef2 = 7;         // Work

    // 可以创建任何类型的引用，包括指针类型
    int* intP;
    int*& ptrRef = intP;
    ptrRef = new int;
    *ptrRef = 5;

    // 对引用取地址的结果与对被引用变量去地址的结果相同
    // 无法声明引用的引用，或者指向引用的指针

    // int myArray[getArraySize()];         // Invalid in C++
    int myArray[getArraySize()];            // OK

    constexpr Rect r(8,2);
    int myArray1[r.getArea()];              // OK

    return 0;
}
