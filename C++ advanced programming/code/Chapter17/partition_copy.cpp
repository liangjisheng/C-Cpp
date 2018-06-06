#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// partition_copy()算法将一个来源的元素复制到两个不同的目标，
// 选择每个元素特定目标的依据是谓词的结果：true or false,
// 返回一对迭代器，分别引用两个目标范围最后一个复制的元素
// 的后一个位置，可以与erase()结合使用，删除两个目标范围
// 中多余的元素

int main()
{
    vector<int>  vec, vecOdd, vecEven;

    for(int i = 0; i <= 9; ++i)
        vec.push_back(i);

    vecOdd.resize(vec.size());
    vecEven.resize(vec.size());

    auto pairIters = partition_copy(vec.cbegin(), vec.cend(),
                    vecEven.begin(), vecOdd.begin(),
                    [](int i) { return i % 2 == 0; });

    vecEven.erase(pairIters.first, vecEven.end());
    vecOdd.erase(pairIters.second, vecOdd.end());

    cout << "Even numbers: ";
    for(const auto& i : vecEven)
        cout << i << ' ';
    cout << endl;

    cout << "Odd numbers: ";
    for(const auto& i : vecOdd)
        cout << i << ' ';
    cout << endl;


    // partition()算法给序列排序，是谓词返回true的所有元素放在前面
    // 返回false的所有元素放在后面，
    partition(vec.begin(), vec.end(),
              [](int i){ return i % 2 == 0;});

    cout << "partitioned result: ";
    for(const auto& i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
