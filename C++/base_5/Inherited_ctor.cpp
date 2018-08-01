
// 可以继承基类的构造函数

#include <iostream>
using namespace std;

class Super{
public:
    Super(const string& str);
private:
    string mStr;
};

class Sub : public Super{
public:
    using Super::Super;
    Sub(int i);
private:
    int mInt;
};

int main()
{
    Sub sub1(1);
    Sub sub2("hello");

    return 0;
}

Super::Super(const string& str){
    cout << "Super ctor version" << endl;
    mStr = str;
}

Sub::Sub(int i){
    cout << "Sub ctor version" << endl;
    mInt = i;
}
