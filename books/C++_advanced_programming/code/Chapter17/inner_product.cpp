#include <iostream>
#include <vector>
#include <numeric>  // for inner_product, and iota

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4 };
    vector<int> v2{9, 8, 7, 6 };
    // 计算两个序列的内积
    cout << inner_product(v1.cbegin(), v1.cend(),
                          v2.cbegin(), 0) << endl;

    // iota算法生成一个指定范围内的序列值，从给定的值开始，
    // 并应用operator++生成每个后续后续值，算法可用于任意
    // 实现了operator++的元素类型
    vector<int> vec(10);
    // 第一个元素从5开始
    iota(vec.begin(), vec.end(),5);
    cout << "values: ";
    for(auto& i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
