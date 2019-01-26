#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void func(int num, const string& str)
{
    cout << "func(" << num << ", " << str << ")" << endl;
}

bool isEven(int num)
{
    return num % 2 == 0;
}

// process接受一个对vector的引用和std::function，对vector中的
// 每个元素调用f, f可以看成是一个回调
void process(const vector<int>& vec, function<void(int)> f)
{
    for(auto& i : vec)
        f(i);
}

void print(int num)
{
    cout << num << ' ';
}

int main()
{
    // std::function可用来创建指向函数、函数对象、或lambda
    // 表示式的类型；从根本上说可以指向任何可调用的对象。
    // 被称为多态函数包装器，可以当成函数指针使用，
    // 还可以用作实现回调的函数的参数
    // std::function<R(ArgTypes...)>
    // R是函数的返回类型，ArgTypes是参数列表

    // 可通过f1调用func()
    function<void(int, const string&)> f1 = func;
    f1(1, "test");

    // 使用auto关键字，不需要指定具体的类型
    auto f2 = func;
    f2(2, "test");

    // 由于std::function类型的行为和函数指针一致，因此可以
    // 传递给STL算法
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    copy(vec.begin(), vec.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    function<bool(int)> f3 = isEven;
    int cnt = count_if(vec.cbegin(), vec.cend(), f3);
    cout << cnt << " even numbers" << endl;


    cout << endl;
    process(vec, print);
    cout << endl;

    int sum = 0;
    process(vec, [&sum](int num){ sum += num; });
    cout << "sum = " << sum << endl;

    return 0;
}
