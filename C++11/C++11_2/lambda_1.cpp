#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void test()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
    int event_count = 0;
    for_each(v.begin(), v.end(),
             [&event_count](int val)
    {
        if (!(val & 1))
            ++event_count;
    });

    cout << "The number of even is " << event_count << endl;
}


int main()
{
    vector<int> v { 1, 3, 5, 2, 6, 10 };
    int value = 3;
    // 按值捕获value
    int count = std::count_if(v.begin(), v.end(), [value](int x) { return x > value; });
    cout << count << endl;

    // 使用generate函数生成斐波那契数列，保存在数组中
    vector<int> v1(10);
    int a = 0, b = 1;
    // 按引用捕获a, b
    std::generate(v1.begin(), v1.end(),
                  [&a, &b]
    {
        int value = b;
        b = b + a;
        a = value;
        return value;
    }
    );

    std::copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    test();

    return 0;
}
