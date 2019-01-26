#include <iostream>
// 初始化列表简化了参数数量可变函数的编写
// 初始化列表中的元素都应该是同一种预定义类型
#include <initializer_list>
using namespace std;

int makeSum(initializer_list<int> lst){
    int total = 0;
    for(const auto& value : lst){
        total += value;
    }
    return total;
}

int main()
{
    int a = makeSum({1,2,3});
    int b = makeSum({10,20,30,40,50,60});
    // 最后一个元素是double,可能会导致编译错误或者给出警告
    int c = makeSum({1,2,1.2});
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
