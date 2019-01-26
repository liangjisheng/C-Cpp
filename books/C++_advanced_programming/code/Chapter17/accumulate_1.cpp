#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// accumulate()计算容器中的总和或其它算术值，计算指定范围中
// 元素的总和。在<numeric>中声明，而不是在<algorithm>中声明

double arithmeticMean(const vector<int>& src)
{
    // 第三个参数表示初值
    double sum = accumulate(src.begin(),src.end(),0);
    return sum / src.size();
}

int product(int num1,int num2)
{
    return num1 * num2;
}

// accumulate()允许调用者指定要执行的操作，而不是执行默认的加法
double geometricMean(const vector<int>& src)
{
    // double mult = accumulate(src.begin(),src.end(),1,product);

    // 也可以使用lambda表达式
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
