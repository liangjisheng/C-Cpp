#include <iostream>
#include <random>
#include <fstream>
#include <map>
#include <functional>

using namespace std;

int main()
{
    // ����100���1��99֮����������Ȼ�����1��99֮���ĳ��
    // ���ֱ����ѡ��Ĵ��������������һ��map�У�
    const unsigned int kStart = 1;
    const unsigned int kEnd = 99;
    // ��������
    const unsigned int kIterations = 1000000;
    // Uniform Mersenne Twister�����ȷֲ���÷ɭ��ת�㷨
    random_device rndDevice;
    mt19937 eng(rndDevice());
    uniform_int_distribution<int> dist(kStart, kEnd);
    auto gen = bind(dist, eng);         // eng�󶨵�dist�ĵ�һ������
    map<unsigned int, unsigned int> m;
    for(unsigned int i = 0; i < kIterations; ++i)
    {
        int rnd = gen();
        // Search map for a key = rnd. If found, add 1 to the value associated
        // with that key. If not found, add the key to the map with value 1.
        ++(m[rnd]);
    }

    // Write to a CSV file,�����õ��ӱ������
    ofstream of("res.csv");
    for(unsigned int i = kStart; i <= kEnd; ++i)
    {
        of << i << ",";
        auto res = m.find(i);
        of << (res != m.end() ? res->second : 0) << endl;
    }
    of.close();

    m.clear();


    // ��һ������Ϊ��̬�ֲ��ľ�ֵ���ڶ�������Ϊ��׼��
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
