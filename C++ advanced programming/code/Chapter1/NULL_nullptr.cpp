#include <iostream>

using namespace std;

void func(char* str){
    cout<<"char* version"<<endl;
}

void func(int i){
    cout<<"int version"<<endl;
}

int main()
{
    // NULL不是指针，而等价于整数0，所以实际调用的是func()的整数版本，
    func(NULL);

    // nullptr 是真正的空指针常量,下面会调用func()的char*版本
    func(nullptr);

    return 0;
}
