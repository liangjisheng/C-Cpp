#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// accumulate()���������е��ܺͻ���������ֵ������ָ����Χ��
// Ԫ�ص��ܺ͡���<numeric>����������������<algorithm>������

double arithmeticMean(const vector<int>& src)
{
    // ������������ʾ��ֵ
    double sum = accumulate(src.begin(),src.end(),0);
    return sum / src.size();
}

int product(int num1,int num2)
{
    return num1 * num2;
}

// accumulate()���������ָ��Ҫִ�еĲ�����������ִ��Ĭ�ϵļӷ�
double geometricMean(const vector<int>& src)
{
    // double mult = accumulate(src.begin(),src.end(),1,product);

    // Ҳ����ʹ��lambda���ʽ
    double mult = accumulate(src.begin(),src.end(),1,
                             [](int num1,int num2){ return num1 * num2; });

    return pow(mult,1.0 / src.size());
}

int main()
{
    vector<int> coll = { 1,2,3,4,5,6,7};
    cout << arithmeticMean(coll) << endl;

    cout << geometricMean(coll) << endl;

    return 0;
}
