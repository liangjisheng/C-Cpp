#include <iostream>
#include <random>
#include <fstream>
#include <map>
#include <functional>

using namespace std;

int main()
{
    // 生成100万个1到99之间的随机数，然后计算1到99之间的某个
    // 数字被随机选择的次数，结果保存在一个map中，
    const unsigned int kStart = 1;
    const unsigned int kEnd = 99;
    // 迭代次数
    const unsigned int kIterations = 1000000;
    // Uniform Mersenne Twister，均匀分布的梅森旋转算法
    random_device rndDevice;
    mt19937 eng(rndDevice());
    uniform_int_distribution<int> dist(kStart, kEnd);
    auto gen = bind(dist, eng);         // eng绑定到dist的第一个参数
    map<unsigned int, unsigned int> m;
    for(unsigned int i = 0; i < kIterations; ++i)
    {
        int rnd = gen();
        // Search map for a key = rnd. If found, add 1 to the value associated
        // with that key. If not found, add the key to the map with value 1.
        ++(m[rnd]);
    }

    // Write to a CSV file,可以用电子表格程序打开
    ofstream of("res.csv");
    for(unsigned int i = kStart; i <= kEnd; ++i)
    {
        of << i << ",";
        auto res = m.find(i);
        of << (res != m.end() ? res->second : 0) << endl;
    }
    of.close();

    m.clear();


    // 第一个参数为正态分布的均值，第二个参数为标准差
    normal_distribution<double> distNormal(50, 10);
    auto gen1 = bind(distNormal, eng);
    for(unsigned int i = 0; i < kIterations; ++i)
    {
        int rnd = static_cast<int>(gen1());
        // Search map for a key = rnd. If found, add 1 to the value associated
        // with that key. If not found, add the key to the map with value 1.
        ++(m[rnd]);
    }

    // Write to a CSV file
    of.open("res_normal.csv");
    for(unsigned int i = kStart; i <= kEnd; ++i)
    {
        of << i << ",";
        auto res = m.find(i);
        of << (res != m.end() ? m[i] : 0) << endl;
    }
    of.close();

    return 0;
}
