#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main()
{
    pair<string,int> myPair("hello",5);
    pair<string,int> myOtherPair;
    // Can assign directory to first and second
    myOtherPair.first = "hello";
    myOtherPair.second = 6;
    // Copy constructor
    // pair 中使用指针是为危险的，pair复制构造函数和赋值运算符只
    // 对指针类型进行浅复制和赋值。在pair中应当使用智能指针
    pair<string,int> myThirdPair(myOtherPair);
    // operator<
    if(myPair < myOtherPair)
        cout << "myPair is less than myOtherPair" << endl;
    else
        cout << "myPair is greater than myOtherPair" << endl;

    // operator==
    if(myOtherPair == myThirdPair)
        cout << "myOtherPair is equal to myThirdPair" << endl;
    else
        cout << "myOtherPair is not equal to myThirdPair" << endl;

    return 0;
}
