#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// partition_copy()�㷨��һ����Դ��Ԫ�ظ��Ƶ�������ͬ��Ŀ�꣬
// ѡ��ÿ��Ԫ���ض�Ŀ���������ν�ʵĽ����true or false,
// ����һ�Ե��������ֱ���������Ŀ�귶Χ���һ�����Ƶ�Ԫ��
// �ĺ�һ��λ�ã�������erase()���ʹ�ã�ɾ������Ŀ�귶Χ
// �ж����Ԫ��

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


    // partition()�㷨������������ν�ʷ���true������Ԫ�ط���ǰ��
    // ����false������Ԫ�ط��ں��棬
    partition(vec.begin(), vec.end(),
              [](int i){ return i % 2 == 0;});

    cout << "partitioned result: ";
    for(const auto& i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
