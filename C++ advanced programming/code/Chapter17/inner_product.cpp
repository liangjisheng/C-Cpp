#include <iostream>
#include <vector>
#include <numeric>  // for inner_product, and iota

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4 };
    vector<int> v2{9, 8, 7, 6 };
    // �����������е��ڻ�
    cout << inner_product(v1.cbegin(), v1.cend(),
                          v2.cbegin(), 0) << endl;

    // iota�㷨����һ��ָ����Χ�ڵ�����ֵ���Ӹ�����ֵ��ʼ��
    // ��Ӧ��operator++����ÿ����������ֵ���㷨����������
    // ʵ����operator++��Ԫ������
    vector<int> vec(10);
    // ��һ��Ԫ�ش�5��ʼ
    iota(vec.begin(), vec.end(),5);
    cout << "values: ";
    for(auto& i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
