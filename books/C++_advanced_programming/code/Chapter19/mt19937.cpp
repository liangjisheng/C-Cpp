#include <iostream>
#include <random>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    // 在生成随机数之前，首先要创建一个引擎实例，如果使用一个
    // 基于软件的引擎，则还需要定义分布。
    // 与旧式的srand()/rand()生成器一样，基于软件的引擎也需要
    // 使用种子进行初始化。srand()的种子常常是当前时间。
    // 在现代C++中，建议不使用任何基于时间的种子，而使用
    // random_device生成一个种子
    random_device rndDevice;
    mt19937 eng(rndDevice());
    // 接下来定义分布，使用范围在1-99之间的均匀分布
    uniform_int_distribution<int> dist(1, 99);

    // 调用名为分布名称的函数，并将引擎作为参数传入，就可以
    // 生成随机数了
    cout << dist(eng) << endl;

    auto gen = bind(dist, eng);
    vector<int> vec(10);
    // 传入回调函数gen,就相当于dist(gen)
    generate(vec.begin(), vec.end(), gen);

    // print
    copy(vec.cbegin(), vec.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
