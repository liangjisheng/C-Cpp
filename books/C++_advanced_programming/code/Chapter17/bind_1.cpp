#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void func(int num, const string& str)
{
    cout << "func(" << num << "," << str << ")" << endl;
}

void increment(int& value)
{
    ++value;
}

void overload(int num) {}

void overload(float f) {}

bool greaterthan100(int num)
{
    return num > 100;
}

int main()
{
    string str = "abc";
    // placeholders::_1 定义在std::placeholders名称空间中
    // _1指定了调用func()时，f1()的第一个参数应该出现的位置
    // 之后，就可以用一个整型参数调用f1()
    auto f1 = bind(func, placeholders::_1, str);
    f1(12);

    // bind()还可以用于重新排列参数的顺序
    auto f2 = bind(func, placeholders::_2, placeholders::_1);
    f2("test", 32);


    // <functional>头文件定义了std::ref()和std::cref()辅助函数，
    // 分别用于绑定引用或者const引用。
    int index = 0;
    increment(index);
    cout << index << endl;

    // 如果用bind()调用，index的值就不递增，因为建立了index的一个
    // 副本，并把这个副本的引用绑定到increment()函数的第一个参数上
    index = 0;
    auto incr = bind(increment,index);
    incr(index);
    cout << index << endl;

    // 使用std::ref()会正确传递对应的引用，会递增index
    index = 0;
    auto incr1 = bind(increment, ref(index));
    incr1(index);
    cout << index << endl;


    // 绑定重载函数是，必须显示的指定绑定这两个重载中的哪一个
    auto f4 = bind((void(*)(float))overload, placeholders::_1);


    // 使用bind()将greater_equal()的第二个参数绑定到固定值100
    vector<int> vec{1,5,20,50,101};
    auto it = find_if(vec.begin(), vec.end(),
                      bind(greater_equal<int>(), placeholders::_1, 100));
    if(it == vec.end())
        cout << "No number greater than 100." << endl;
    else
        cout << "Found a number greater than 100 is :" << *it << endl;

    // 取反器，计算谓词结果的反结果
    // not1(),表示这个操作数必须是一元函数(即接受一个参数的函数)
    // 如果操作数是二元函数(即接受两个参数的函数)，那么必须改用not2()
    function<bool(int)> f5 = greaterthan100;
    it = find_if(vec.begin(), vec.end(), not1(f5));
    if(it == vec.end())
        cout << "All numbers is greater than 100." << endl;
    else
        cout << "Found a number less than 100 is :" << *it << endl;
    // 以上看出，仿函数的使用会使得表达式非常复杂，建议尽量使用lambda
    // 表达式，而不是仿函数

    return 0;
}
